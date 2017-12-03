//
// Copyright (c) 2017, chunquedong
// Licensed under the Apache Licene 2.0
//
//  Created by yangjiandong on 2017/8/20.
//

#include "PodGen.hpp"
#include "FCodeUtil.hpp"


PodGen::PodGen(PodLoader *podMgr, const std::string& podName) : podMgr(podMgr), podName(podName) {
    pod = podMgr->findPod(podName);
    
    allTypes.clear();
    allTypes.reserve(pod->types.size());
    for (int i=0; i<pod->types.size(); ++i) {
        FType *type = &pod->types[i];
        TypeGen gtype(this, type);
        gtype.c_sortFlag = 0;
        
        //if (gtype.name != "testlib_Main") continue;
        allTypes.push_back(gtype);
    }
    
    for (int i=0; i<allTypes.size(); ++i) {
        TypeGen *t = &allTypes[i];
        typeMap[t->name] = t;
    }
    
    topoSortType();
}

void PodGen::gen(std::string &path) {
    std::string headerFile = path + podName + ".h";
    Printer headerPrinter(headerFile.c_str());
    genHeader(&headerPrinter);
    
    std::string impleFile = path + podName + ".c";
    Printer implePrinter(impleFile.c_str());
    genImple(&implePrinter);
}

void PodGen::horizontalLine(Printer *printer, const char *name) {
    printer->newLine();
    printer->_print("//");
    for (int i=0; i<80; ++i) {
        printer->_print("#");
    }
    if (name) {
        printer->_print("  ");
        printer->_print(name);
    }
    printer->newLine();
    printer->newLine();
}

void PodGen::genHeader(Printer *printer) {
    printer->println("#ifndef _%s_h_", podName.c_str());
    printer->println("#define _%s_h_", podName.c_str());
    printer->println("#include \"runtime.h\"");
    for (int i=0; i<pod->c_dependPods.size(); ++i) {
        std::string& dep = pod->c_dependPods[i];
        printer->println("#include \"%s.h\"", dep.c_str());
    }
    printer->newLine();
    
    horizontalLine(printer, "type declare");
    for (int i=0; i<sortedTypes.size(); ++i) {
        TypeGen *gtype = sortedTypes[i];
        gtype->genTypeDeclare(printer);
        printer->newLine();
    }
    
    horizontalLine(printer, "struct");
    for (int i=0; i<sortedTypes.size(); ++i) {
        TypeGen *gtype = sortedTypes[i];
        gtype->genStruct(printer);
        printer->newLine();
        gtype->genStaticField(printer, true);
        printer->newLine();
    }
    
    horizontalLine(printer, "method declare");
    for (int i=0; i<sortedTypes.size(); ++i) {
        TypeGen *gtype = sortedTypes[i];
        gtype->genMethodDeclare(printer);
        printer->newLine();
    }
    
    horizontalLine(printer, "virtual table");
    for (int i=0; i<sortedTypes.size(); ++i) {
        TypeGen *gtype = sortedTypes[i];
        gtype->genVTable(printer);
        printer->newLine();
    }
    printer->println("#endif //_%s_h_", podName.c_str());
}

void PodGen::genImple(Printer *printer) {
    
    printer->println("#include \"%s.h\"", podName.c_str());
    printer->newLine();
    
    for (int i=0; i<sortedTypes.size(); ++i) {
        TypeGen *gtype = sortedTypes[i];
        gtype->genImple(printer);
        //printer->newLine();
    }
}

std::string PodGen::getTypeRefName(uint16_t tid) {
    return FCodeUtil::getTypeRefName(pod, tid, true);
}


//////////////////////////////////////////////////
// sort

static TypeGen *exitsBase(PodGen *pod, std::string &typeName) {
    for (size_t i=0,n=pod->allTypes.size(); i<n; ++i) {
        TypeGen &type = pod->allTypes[i];
        
        if (type.c_sortFlag != 0 ) {
            continue;
        }
        
        if (type.name == typeName) {
            return &type;
        }
    }
    return NULL;
}

static TypeGen *getOne(PodGen *pod) {
    for (size_t i=0,n=pod->allTypes.size(); i<n; ++i) {
        TypeGen &type = pod->allTypes[i];
        if (type.c_sortFlag != 0 ) {
            continue;
        }
        return &type;
    }
    return NULL;
}

void PodGen::topoSortType() {
    sortedTypes.clear();
    
    TypeGen *type = getOne(this);
    while (type) {
        
        if (type->name == "sys_Obj") {
            sortedTypes.push_back(type);
            type->c_sortFlag = 1;
            type = getOne(this);
            continue;
        }
        
        std::string baseName = getTypeRefName(type->type->meta.base);
        
        TypeGen *base = exitsBase(this, baseName);
        if (!base) {
            sortedTypes.push_back(type);
            type->c_sortFlag = 1;
            type = getOne(this);
        } else {
            type = base;
        }
    }
}

////////////////////////////////////////////////////////////

TypeGen* PodGen::findType(std::string &name) {
    auto it = typeMap.find(name);
    if (it == typeMap.end()) {
        return NULL;
    } else {
        return it->second;
    }
}

