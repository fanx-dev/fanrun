//
//  Env.h
//  fcode
//
//  Created by yangjiandong on 15/8/2.
//  Copyright (c) 2015年 yangjiandong. All rights reserved.
//

#ifndef __fcode__Env__
#define __fcode__Env__

#ifdef  __cplusplus
extern  "C" {
#endif

#include "Obj.h"
#include <setjmp.h>

typedef void *fr_FVM;
typedef void *fr_Env;

////////////////////////////
// VM
////////////////////////////

fr_FVM fr_startVm();
void fr_stopVm(fr_FVM vm);
fr_Env fr_getEnv(fr_FVM vm);

void fr_initEnv(fr_Env env);
void fr_releaseEnv(fr_Env env);

////////////////////////////
// Exception
////////////////////////////
    
void fr_pushFrame(const char*func);
void fr_popFrame();

jmp_buf *fr_pushJmpBuf(fr_Env self);
jmp_buf *fr_popJmpBuf(fr_Env self);

fr_Obj fr_getErr(fr_Env self);
void fr_throwErr(fr_Env self, fr_Obj err);
fr_Obj fr_clearErr(fr_Env self);

////////////////////////////
// GC
////////////////////////////

void fr_addGlobalRef(fr_Env self, fr_Obj obj);
fr_Obj fr_malloc(fr_Env self, int size, fr_Type vtable);
void fr_gc(fr_Env self);
    
////////////////////////////
// Util
////////////////////////////
fr_Obj fr_newStrUtf8(fr_Env self, const char *bytes);

#ifdef  __cplusplus
}
#endif

#endif /* defined(__fcode__Env__) */