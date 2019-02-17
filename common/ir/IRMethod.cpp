//
// Copyright (c) 2017, chunquedong
// Licensed under the Apache Licene 2.0
//
//  Created by yangjiandong on 16/9/10.
//

#include "IRMethod.h"
#include "FCodeUtil.hpp"

void Block::addStmt(Stmt *stmt) {
    stmts.push_back(stmt);
}

Var &Block::newVar(uint16_t typeRefId) {
    Var var;
    var.index = (int)locals.size();
    var.block = this;
    //if (typeRefId != -1) {
        var.type.setFromTypeRef(curPod, typeRefId);
    //}

    locals.push_back(var);
    return locals.back();
}

Var &Block::newVarAs(const TypeInfo &type) {
    Var var;
    var.index = (int)locals.size();
    var.block = this;
    var.type = type;
    locals.push_back(var);
    return locals.back();
}

void Block::print(IRMethod *method, Printer& printer, int pass) {
    //print export temp var
    if (pass == 0) {
        bool has = false;
        for (int i=0; i<locals.size(); ++i) {
            Var &v = locals[i];
            if (v.isExport) {
                printer.printf("%s %s; ", v.type.getName().c_str(), v.name.c_str());
                has = true;
            }
        }
        if (has) {
            printer.newLine();
        }
        return;
    }
    
    //print jump label num
    char *s = printer.format("l__%d:\n", pos);
    printer._print(s);
    
    //print first exception try stmt
    int start = 0;
    int end = (int)stmts.size();
    bool printLast = false;
    if (stmts.size() > 0) {
        if (dynamic_cast<ExceptionStmt*>(stmts[0])) {
            stmts[0]->print(printer);
            printer.newLine();
            ++start;
        }
        if (dynamic_cast<ExceptionStmt*>(stmts[end-1])) {
            printLast = true;
            --end;
        }
    }
    
    printer.println("{");
    //print temp var
    bool has = false;
    for (int i=0; i<locals.size(); ++i) {
        Var &v = locals[i];
        if (!v.isExport) {
            printer.printf("%s %s; ", v.type.getName().c_str(), v.name.c_str());
            has = true;
        }
    }
    if (has) {
        printer.newLine();
    }

    //print stmts
    for (int i=start; i<end; ++i) {
        stmts[i]->print(printer);
        printer.newLine();
    }
    
    //set temp ver to NULL
    has = false;
    for (int i=0; i<locals.size(); ++i) {
        Var &v = locals[i];
        if (!v.isExport && !v.type.isValue) {
            if (has == false) {
                printer.println("//reset temp var");
            }
            printer.printf("%s = NULL; ", v.name.c_str());
            has = true;
        }
    }
    if (has) {
        printer.newLine();
    }
    printer.println("}");
    
    //print last exception tryEnd stmt
    if (printLast) {
        stmts[end]->print(printer);
        printer.newLine();
    }
}

IRMethod::IRMethod(FPod *curPod, FMethod *method) :
    curPod(curPod),
    method(method) {
    returnType = method->returnType;
    selfType = method->c_parent->meta.self;
    paramCount = method->paramCount;
}

void IRMethod::print(Printer& printer, int pass) {
    
    if (pass == 0) {
        printer.printf("%s(", name.c_str());
        for(int i=0; i<paramCount; ++i) {
            Var &v = blocks[0]->locals[i];
            if (i != 0) printer.printf(", ");
            printer.printf("%s %s", v.type.getName().c_str(), v.name.c_str());
        }
        printer.println(")");
    }
    else if (pass == 1) {
        
        for(int i=paramCount; i<blocks[0]->locals.size(); ++i) {
            Var &v = blocks[0]->locals[i];
            printer.printf("%s %s; ", v.type.getName().c_str(), v.name.c_str());
        }
        printer.newLine();
        
        for (int i=1; i<blocks.size(); ++i) {
            Block *b = blocks[i];
            b->print(this, printer, 0);
        }
        for (int i=1; i<blocks.size(); ++i) {
            Block *b = blocks[i];
            b->print(this, printer, 1);
        }
    }
}
