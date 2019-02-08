//
//  sys_native.c
//  run
//
//  Created by yangjiandong on 2017/12/31.
//  Copyright © 2017年 yangjiandong. All rights reserved.
//

#include "sys.h"
#include "runtime.h"

#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>

//////////////////////////////////////////////////////////
extern "C" {
sys_Int strHash(sys_Str str);
size_t utf8encode(wchar_t *us, char *des, size_t n, int *illegal);
size_t utf8decode(char const *str, wchar_t *des, size_t n, int *illegal);
}
fr_Obj fr_newStrUtf8(fr_Env __env, const char *bytes) {
    size_t len;
    size_t size;
    len = strlen(bytes);
    size = len + 1;
    
    sys_Str str = FR_ALLOC(sys_Str);
    
    str->data = (wchar_t*)malloc(sizeof(wchar_t)*size);
    //mbstowcs();
    //str->size = mbstowcs(cstr, str->data, len);
    str->size = utf8decode(bytes, str->data, size, NULL);
    
    str->hashCode = strHash(str);
    str->utf8 = NULL;
    return str;
}
fr_Obj fr_newStr(fr_Env __env, const wchar_t *data, size_t size) {
    sys_Str str = FR_ALLOC(sys_Str);
    
    str->data = (wchar_t*)malloc(sizeof(wchar_t)*(size+1));
    wcsncpy(str->data, data, size);
    str->size = size;
    str->hashCode = strHash(str);
    str->utf8 = NULL;
    return str;
}
fr_Obj fr_newStrNT(fr_Env __env, const wchar_t *data) {
    size_t size = wcslen(data);
    return fr_newStr(__env, data, size);
}
const char *fr_getStrUtf8(fr_Env env__, fr_Obj obj, bool *isCopy) {
    size_t size;
    size_t realSize;
    sys_Str str = (sys_Str)obj;
    if (str->utf8) return str->utf8;
    size = str->size * 4 + 1;
    char *utf8 = (char*)malloc(size);
    realSize = utf8encode(str->data, utf8, size, NULL);
    utf8[realSize] = 0;
    str->utf8 = utf8;
    return str->utf8;
}

////////////////////////////////////////////////////////////////
#ifdef GEN
fr_Obj fr_toSysType(fr_Env __env, fr_Class clz) {
    if (!clz->sysType) {
        sys_Type type = FR_ALLOC(sys_Type);
        type->rawClass = clz;
        clz->sysType = type;
    }
    return clz->sysType;
}

fr_Class fr_fromSysType(fr_Env __env, fr_Obj clz) {
    //return clz->sysType;
    return NULL;
}
#else
fr_Obj fr_toSysType(fr_Env __env, fr_Class clz) {
    //;
    return NULL;
}

fr_Class fr_fromSysType(fr_Env __env, fr_Obj clz) {
    return NULL;
}
#endif

////////////////////////////////////////////////////////////////
void fr_throwNPE(fr_Env __env) {
    sys_NullErr npe = FR_ALLOC(sys_NullErr);
    FR_THROW(npe);
}
////////////////////////////////////////////////////////////////
#include <unordered_map>
#include <mutex>

std::mutex pool_mutex;

fr_Obj fr_box_int(fr_Env __env, sys_Int_val val) {
    fr_Obj obj;
    static std::unordered_map<sys_Int_val, fr_Obj> map;
    if ((val < 256 && val > -256)
        || val == sys_Int_maxVal
        || val == sys_Int_minVal) {
        
        std::lock_guard<std::mutex> lock(pool_mutex);
        
        auto itr = map.find(val);
        if (itr != map.end()) {
            return itr->second;
        }
        
        FR_BOXING_VAL(obj, val, sys_Int, sys_Obj);
        obj = fr_addGlobalRef(__env, obj);
        map[val] = obj;
        return obj;
    }
    FR_BOXING_VAL(obj, val, sys_Int, sys_Obj);
    return obj;
}
fr_Obj fr_box_float(fr_Env __env, sys_Float_val val) {
    fr_Obj obj;
    static std::unordered_map<sys_Int_val, fr_Obj> map;
    if (val == 0 || val == 1 || val == -1 || val == 0.5
         || val == sys_Float_e
         || val == sys_Float_pi
         || val == sys_Float_negInf
         || val == sys_Float_posInf) {
        
        std::lock_guard<std::mutex> lock(pool_mutex);
        
        auto itr = map.find(val);
        if (itr != map.end()) {
            return itr->second;
        }
        
        FR_BOXING_VAL(obj, val, sys_Int, sys_Obj);
        obj = fr_addGlobalRef(__env, obj);
        map[val] = obj;
        return obj;
    }
    FR_BOXING_VAL(obj, val, sys_Int, sys_Obj);
    return obj;
}
fr_Obj fr_box_bool(fr_Env __env, sys_Bool_val val) {
    static fr_Obj trueObj = nullptr;
    static fr_Obj falseObj = nullptr;
    if (!trueObj) {
        std::lock_guard<std::mutex> lock(pool_mutex);
        FR_BOXING_VAL(trueObj, true, sys_Bool, sys_Obj);
        FR_BOXING_VAL(falseObj, false, sys_Bool, sys_Obj);
        trueObj = fr_addGlobalRef(__env, trueObj);
        falseObj = fr_addGlobalRef(__env, falseObj);
    }
    return val ? trueObj : falseObj;
}