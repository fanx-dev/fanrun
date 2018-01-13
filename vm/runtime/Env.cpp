//
//  Env.cpp
//  fcode
//
//  Created by yangjiandong on 15/8/2.
//  Copyright (c) 2015年 yangjiandong. All rights reserved.
//

#include "Env.hpp"
#include "Vm.hpp"

Env::Env(Vm *vm) : vm(vm), error(0)
, statckStart(NULL) {
    isStoped = false;
    needStop = false;
    statckStart = NULL;
    statckEnd = statckStart;
}

static bool isPointer(Vm *vm, Gc *gc, int64_t pointer) {
    if (pointer == 0) return false;
    if (pointer % 8 != 0) return false;
    GcObj *gcobj = fr_toGcObj((fr_Obj)(pointer));
    if (gcobj < gc->minAddress || gcobj > gc->maxAddress) {
        return false;
    }
#if GC_POINTER_TEST
    //test is Obj ptr
    int64_t type = (int64_t)gc_getType(gcobj);
    if (type % 8 != 0) return false;
    if (vm->classSet.find((fr_Class)type) == vm->classSet.end()) {
        return false;
    }
#endif
    return true;
}

void Env::walkLocalRoot(Gc *gc) {
    if (error) {
        gc->onRoot(fr_toGcObj(error));
    }
    
    void **min = statckStart > statckEnd ? statckEnd : statckStart;
    void **max = statckStart < statckEnd ? statckEnd : statckStart;
    for (void **ptr = min; ptr <= max; ++ptr) {
        if (isPointer(vm, gc, (int64_t)(*ptr))) {
            GcObj *obj = fr_toGcObj((fr_Obj)(*ptr));
            gc->onRoot(obj);
        }
    }
}

////////////////////////////
// Exception
////////////////////////////
#ifdef LONG_JMP_EXCEPTION
jmp_buf *fr_pushJmpBuf(fr_Env self) {
    Env *env = (Env*)self;
    JmpBuf buf;
    env->exception.push_back(buf);
    return &env->exception.back().buf;
}

jmp_buf *fr_popJmpBuf(fr_Env self) {
    Env *env = (Env*)self;
    JmpBuf &back = env->exception.back();
    env->exception.pop_back();
    return &back.buf;
}
jmp_buf *fr_topJmpBuf(fr_Env self) {
    Env *env = (Env*)self;
    JmpBuf &back = env->exception.back();
    return &back.buf;
}
#endif

fr_Obj fr_getErr(fr_Env self) {
    Env *env = (Env*)self;
    return env->error;
}
void fr_setErr(fr_Env self, fr_Obj err) {
    Env *env = (Env*)self;
    env->error = err;
}
void fr_clearErr(fr_Env self) {
    Env *env = (Env*)self;
    env->error = nullptr;
}



