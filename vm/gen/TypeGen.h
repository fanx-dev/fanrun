//
//  GenType.h
//  gen
//
//  Created by yangjiandong on 2017/9/10.
//  Copyright © 2017年 yangjiandong. All rights reserved.
//

#ifndef GenType_h
#define GenType_h

#include <stdio.h>
#include "PodLoader.h"
#include "Printer.h"

class PodGen;
class MethodGen;

class TypeGen {
public:
    PodGen *podGen;
    FType *type;
    int c_sortFlag;
public:
    std::string name;
    bool isValueType;
public:
    TypeGen(PodGen *podGen, FType *type);
    
    void genTypeDeclare(Printer *printer);
    void genStruct(Printer *printer);
    void genVTable(Printer *printer);
    void genTypeInit(Printer *printer);
    void genMethodDeclare(Printer *printer);
    void genInline(Printer *printer);
    void genImple(Printer *printer);
    void genStaticField(Printer *printer, bool isExtern);
    
    void genMethodStub(Printer *printer);
    void genMethodWrap(Printer *printer);
    void genMethodRegister(Printer *printer);
private:
    void genField(Printer *printer);
    void genTypeMetadata(Printer *printer);
    void genVTableInit(Printer *printer);
    void genOverrideVTable(FType *type, std::string &name
                           , Printer *printer, MethodGen &gmethod, std::string from);
    
};



#endif /* GenType_h */
