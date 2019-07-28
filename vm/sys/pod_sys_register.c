#include "vm.h"

int sys_Obj__allocSize__();
void sys_Obj_make(fr_Env env, void *param, void *ret);
void sys_Obj_equals(fr_Env env, void *param, void *ret);
void sys_Obj_compare(fr_Env env, void *param, void *ret);
void sys_Obj_hash(fr_Env env, void *param, void *ret);
void sys_Obj_toStr(fr_Env env, void *param, void *ret);
void sys_Obj_trap(fr_Env env, void *param, void *ret);
void sys_Obj_isImmutable(fr_Env env, void *param, void *ret);
void sys_Obj_toImmutable(fr_Env env, void *param, void *ret);
void sys_Obj_typeof(fr_Env env, void *param, void *ret);
void sys_Obj_finalize(fr_Env env, void *param, void *ret);
void sys_Obj_echo(fr_Env env, void *param, void *ret);
int sys_Num__allocSize__();
void sys_Num_make(fr_Env env, void *param, void *ret);
void sys_Num_toInt(fr_Env env, void *param, void *ret);
void sys_Num_toFloat(fr_Env env, void *param, void *ret);
int sys_Int__allocSize__();
void sys_Int_fromStr(fr_Env env, void *param, void *ret);
void sys_Int_random(fr_Env env, void *param, void *ret);
void sys_Int_privateMake(fr_Env env, void *param, void *ret);
void sys_Int_equals(fr_Env env, void *param, void *ret);
void sys_Int_compare(fr_Env env, void *param, void *ret);
void sys_Int_negate(fr_Env env, void *param, void *ret);
void sys_Int_increment(fr_Env env, void *param, void *ret);
void sys_Int_decrement(fr_Env env, void *param, void *ret);
void sys_Int_mult(fr_Env env, void *param, void *ret);
void sys_Int_multFloat(fr_Env env, void *param, void *ret);
void sys_Int_div(fr_Env env, void *param, void *ret);
void sys_Int_divFloat(fr_Env env, void *param, void *ret);
void sys_Int_mod(fr_Env env, void *param, void *ret);
void sys_Int_modFloat(fr_Env env, void *param, void *ret);
void sys_Int_plus(fr_Env env, void *param, void *ret);
void sys_Int_plusFloat(fr_Env env, void *param, void *ret);
void sys_Int_minus(fr_Env env, void *param, void *ret);
void sys_Int_minusFloat(fr_Env env, void *param, void *ret);
void sys_Int_not(fr_Env env, void *param, void *ret);
void sys_Int_and(fr_Env env, void *param, void *ret);
void sys_Int_or(fr_Env env, void *param, void *ret);
void sys_Int_xor(fr_Env env, void *param, void *ret);
void sys_Int_shiftl(fr_Env env, void *param, void *ret);
void sys_Int_shiftr(fr_Env env, void *param, void *ret);
void sys_Int_shifta(fr_Env env, void *param, void *ret);
void sys_Int_pow(fr_Env env, void *param, void *ret);
void sys_Int_toStr(fr_Env env, void *param, void *ret);
void sys_Int_toHex(fr_Env env, void *param, void *ret);
void sys_Int_toRadix(fr_Env env, void *param, void *ret);
void sys_Int_toChar(fr_Env env, void *param, void *ret);
void sys_Int_toCode(fr_Env env, void *param, void *ret);
void sys_Int_static__init(fr_Env env, void *param, void *ret);
int sys_Void__allocSize__();
void sys_Void_make(fr_Env env, void *param, void *ret);
int sys_StrBuf__allocSize__();
void sys_StrBuf_make(fr_Env env, void *param, void *ret);
void sys_StrBuf_size(fr_Env env, void *param, void *ret);
void sys_StrBuf_capacity(fr_Env env, void *param, void *ret);
void sys_StrBuf_capacity__1(fr_Env env, void *param, void *ret);
void sys_StrBuf_get(fr_Env env, void *param, void *ret);
void sys_StrBuf_getRange(fr_Env env, void *param, void *ret);
void sys_StrBuf_set(fr_Env env, void *param, void *ret);
void sys_StrBuf_addChar(fr_Env env, void *param, void *ret);
void sys_StrBuf_addStr(fr_Env env, void *param, void *ret);
void sys_StrBuf_insert(fr_Env env, void *param, void *ret);
void sys_StrBuf_remove(fr_Env env, void *param, void *ret);
void sys_StrBuf_removeRange(fr_Env env, void *param, void *ret);
void sys_StrBuf_replaceRange(fr_Env env, void *param, void *ret);
void sys_StrBuf_clear(fr_Env env, void *param, void *ret);
void sys_StrBuf_toStr(fr_Env env, void *param, void *ret);
void sys_StrBuf_finalize(fr_Env env, void *param, void *ret);
int sys_Func__allocSize__();
void sys_Func_make(fr_Env env, void *param, void *ret);
void sys_Func_arity(fr_Env env, void *param, void *ret);
void sys_Func_callList(fr_Env env, void *param, void *ret);
void sys_Func_callOn(fr_Env env, void *param, void *ret);
void sys_Func_call(fr_Env env, void *param, void *ret);
void sys_Func_bind(fr_Env env, void *param, void *ret);
void sys_Func_enterCtor(fr_Env env, void *param, void *ret);
void sys_Func_exitCtor(fr_Env env, void *param, void *ret);
void sys_Func_checkInCtor(fr_Env env, void *param, void *ret);
void sys_Func_call__0(fr_Env env, void *param, void *ret);
void sys_Func_call__1(fr_Env env, void *param, void *ret);
void sys_Func_call__2(fr_Env env, void *param, void *ret);
void sys_Func_call__3(fr_Env env, void *param, void *ret);
void sys_Func_call__4(fr_Env env, void *param, void *ret);
void sys_Func_call__5(fr_Env env, void *param, void *ret);
void sys_Func_call__6(fr_Env env, void *param, void *ret);
void sys_Func_call__7(fr_Env env, void *param, void *ret);
int sys_Err__allocSize__();
void sys_Err_make(fr_Env env, void *param, void *ret);
void sys_Err_msg(fr_Env env, void *param, void *ret);
void sys_Err_cause(fr_Env env, void *param, void *ret);
void sys_Err_trace(fr_Env env, void *param, void *ret);
void sys_Err_traceToStr(fr_Env env, void *param, void *ret);
void sys_Err_toStr(fr_Env env, void *param, void *ret);
int sys_Str__allocSize__();
void sys_Str_privateMake(fr_Env env, void *param, void *ret);
void sys_Str_fromChars(fr_Env env, void *param, void *ret);
void sys_Str_hash(fr_Env env, void *param, void *ret);
void sys_Str_size(fr_Env env, void *param, void *ret);
void sys_Str_intern(fr_Env env, void *param, void *ret);
void sys_Str_find(fr_Env env, void *param, void *ret);
void sys_Str_findr(fr_Env env, void *param, void *ret);
void sys_Str_get(fr_Env env, void *param, void *ret);
void sys_Str_getRange(fr_Env env, void *param, void *ret);
void sys_Str_plus(fr_Env env, void *param, void *ret);
void sys_Str_chars(fr_Env env, void *param, void *ret);
void sys_Str_toUtf8(fr_Env env, void *param, void *ret);
void sys_Str_fromUtf8(fr_Env env, void *param, void *ret);
void sys_Str_finalize(fr_Env env, void *param, void *ret);
void sys_Str_format(fr_Env env, void *param, void *ret);
void sys_Str_static__init(fr_Env env, void *param, void *ret);
int sys_Bool__allocSize__();
void sys_Bool_privateMake(fr_Env env, void *param, void *ret);
void sys_Bool_equals(fr_Env env, void *param, void *ret);
void sys_Bool_not(fr_Env env, void *param, void *ret);
void sys_Bool_and(fr_Env env, void *param, void *ret);
void sys_Bool_or(fr_Env env, void *param, void *ret);
void sys_Bool_xor(fr_Env env, void *param, void *ret);
void sys_Bool_static__init(fr_Env env, void *param, void *ret);
int sys_ObjArray__allocSize__();
void sys_ObjArray_make(fr_Env env, void *param, void *ret);
void sys_ObjArray_get(fr_Env env, void *param, void *ret);
void sys_ObjArray_set(fr_Env env, void *param, void *ret);
void sys_ObjArray_size(fr_Env env, void *param, void *ret);
void sys_ObjArray_realloc(fr_Env env, void *param, void *ret);
void sys_ObjArray_fill(fr_Env env, void *param, void *ret);
void sys_ObjArray_copyFrom(fr_Env env, void *param, void *ret);
void sys_ObjArray_finalize(fr_Env env, void *param, void *ret);
void sys_ObjArray_fromJava(fr_Env env, void *param, void *ret);
void sys_ObjArray_toJava(fr_Env env, void *param, void *ret);
int sys_ByteArray__allocSize__();
void sys_ByteArray_make(fr_Env env, void *param, void *ret);
void sys_ByteArray_get(fr_Env env, void *param, void *ret);
void sys_ByteArray_set(fr_Env env, void *param, void *ret);
void sys_ByteArray_size(fr_Env env, void *param, void *ret);
void sys_ByteArray_realloc(fr_Env env, void *param, void *ret);
void sys_ByteArray_fill(fr_Env env, void *param, void *ret);
void sys_ByteArray_copyFrom(fr_Env env, void *param, void *ret);
void sys_ByteArray_finalize(fr_Env env, void *param, void *ret);
int sys_Float__allocSize__();
void sys_Float_makeBits(fr_Env env, void *param, void *ret);
void sys_Float_makeBits32(fr_Env env, void *param, void *ret);
void sys_Float_fromStr(fr_Env env, void *param, void *ret);
void sys_Float_random(fr_Env env, void *param, void *ret);
void sys_Float_privateMake(fr_Env env, void *param, void *ret);
void sys_Float_equals(fr_Env env, void *param, void *ret);
void sys_Float_isNaN(fr_Env env, void *param, void *ret);
void sys_Float_negate(fr_Env env, void *param, void *ret);
void sys_Float_mult(fr_Env env, void *param, void *ret);
void sys_Float_multInt(fr_Env env, void *param, void *ret);
void sys_Float_div(fr_Env env, void *param, void *ret);
void sys_Float_divInt(fr_Env env, void *param, void *ret);
void sys_Float_mod(fr_Env env, void *param, void *ret);
void sys_Float_modInt(fr_Env env, void *param, void *ret);
void sys_Float_plus(fr_Env env, void *param, void *ret);
void sys_Float_plusInt(fr_Env env, void *param, void *ret);
void sys_Float_minus(fr_Env env, void *param, void *ret);
void sys_Float_minusInt(fr_Env env, void *param, void *ret);
void sys_Float_bits(fr_Env env, void *param, void *ret);
void sys_Float_bits32(fr_Env env, void *param, void *ret);
void sys_Float_toStr(fr_Env env, void *param, void *ret);
void sys_Float_toLocale(fr_Env env, void *param, void *ret);
void sys_Float_static__init(fr_Env env, void *param, void *ret);
int sys_Type__allocSize__();
void sys_Type_privateMake(fr_Env env, void *param, void *ret);
void sys_Type_of(fr_Env env, void *param, void *ret);
void sys_Type_find(fr_Env env, void *param, void *ret);
void sys_Type_name(fr_Env env, void *param, void *ret);
void sys_Type_qname(fr_Env env, void *param, void *ret);
void sys_Type_signature(fr_Env env, void *param, void *ret);
void sys_Type_base(fr_Env env, void *param, void *ret);
void sys_Type_mixins(fr_Env env, void *param, void *ret);
void sys_Type_inheritance(fr_Env env, void *param, void *ret);
void sys_Type_fits(fr_Env env, void *param, void *ret);
void sys_Type_isVal(fr_Env env, void *param, void *ret);
void sys_Type_isNullable(fr_Env env, void *param, void *ret);
void sys_Type_toNullable(fr_Env env, void *param, void *ret);
void sys_Type_toNonNullable(fr_Env env, void *param, void *ret);
void sys_Type_emptyList(fr_Env env, void *param, void *ret);
void sys_Type_isAbstract(fr_Env env, void *param, void *ret);
void sys_Type_isClass(fr_Env env, void *param, void *ret);
void sys_Type_isConst(fr_Env env, void *param, void *ret);
void sys_Type_isEnum(fr_Env env, void *param, void *ret);
void sys_Type_isFacet(fr_Env env, void *param, void *ret);
void sys_Type_isFinal(fr_Env env, void *param, void *ret);
void sys_Type_isInternal(fr_Env env, void *param, void *ret);
void sys_Type_isMixin(fr_Env env, void *param, void *ret);
void sys_Type_isPublic(fr_Env env, void *param, void *ret);
void sys_Type_isSynthetic(fr_Env env, void *param, void *ret);
void sys_Type_toStr(fr_Env env, void *param, void *ret);
void sys_Type_isJava(fr_Env env, void *param, void *ret);
void sys_Enum_doFromStr(fr_Env env, void *param, void *ret);

void sys_register(fr_Fvm vm) {
    fr_registerMethod(vm, "sys_Obj__allocSize__", (fr_NativeFunc)sys_Obj__allocSize__);
    fr_registerMethod(vm, "sys_Obj_make", sys_Obj_make);
    fr_registerMethod(vm, "sys_Obj_equals", sys_Obj_equals);
    fr_registerMethod(vm, "sys_Obj_compare", sys_Obj_compare);
    fr_registerMethod(vm, "sys_Obj_hash", sys_Obj_hash);
    fr_registerMethod(vm, "sys_Obj_toStr", sys_Obj_toStr);
    fr_registerMethod(vm, "sys_Obj_trap", sys_Obj_trap);
    fr_registerMethod(vm, "sys_Obj_isImmutable", sys_Obj_isImmutable);
    fr_registerMethod(vm, "sys_Obj_toImmutable", sys_Obj_toImmutable);
    fr_registerMethod(vm, "sys_Obj_typeof", sys_Obj_typeof);
    fr_registerMethod(vm, "sys_Obj_finalize", sys_Obj_finalize);
    fr_registerMethod(vm, "sys_Obj_echo", sys_Obj_echo);
    fr_registerMethod(vm, "sys_Num__allocSize__", (fr_NativeFunc)sys_Num__allocSize__);
    fr_registerMethod(vm, "sys_Num_make", sys_Num_make);
    fr_registerMethod(vm, "sys_Num_toInt", sys_Num_toInt);
    fr_registerMethod(vm, "sys_Num_toFloat", sys_Num_toFloat);
    fr_registerMethod(vm, "sys_Int__allocSize__", (fr_NativeFunc)sys_Int__allocSize__);
    fr_registerMethod(vm, "sys_Int_fromStr", sys_Int_fromStr);
    fr_registerMethod(vm, "sys_Int_random", sys_Int_random);
    fr_registerMethod(vm, "sys_Int_privateMake", sys_Int_privateMake);
    fr_registerMethod(vm, "sys_Int_equals", sys_Int_equals);
    fr_registerMethod(vm, "sys_Int_compare", sys_Int_compare);
    fr_registerMethod(vm, "sys_Int_negate", sys_Int_negate);
    fr_registerMethod(vm, "sys_Int_increment", sys_Int_increment);
    fr_registerMethod(vm, "sys_Int_decrement", sys_Int_decrement);
    fr_registerMethod(vm, "sys_Int_mult", sys_Int_mult);
    fr_registerMethod(vm, "sys_Int_multFloat", sys_Int_multFloat);
    fr_registerMethod(vm, "sys_Int_div", sys_Int_div);
    fr_registerMethod(vm, "sys_Int_divFloat", sys_Int_divFloat);
    fr_registerMethod(vm, "sys_Int_mod", sys_Int_mod);
    fr_registerMethod(vm, "sys_Int_modFloat", sys_Int_modFloat);
    fr_registerMethod(vm, "sys_Int_plus", sys_Int_plus);
    fr_registerMethod(vm, "sys_Int_plusFloat", sys_Int_plusFloat);
    fr_registerMethod(vm, "sys_Int_minus", sys_Int_minus);
    fr_registerMethod(vm, "sys_Int_minusFloat", sys_Int_minusFloat);
    fr_registerMethod(vm, "sys_Int_not", sys_Int_not);
    fr_registerMethod(vm, "sys_Int_and", sys_Int_and);
    fr_registerMethod(vm, "sys_Int_or", sys_Int_or);
    fr_registerMethod(vm, "sys_Int_xor", sys_Int_xor);
    fr_registerMethod(vm, "sys_Int_shiftl", sys_Int_shiftl);
    fr_registerMethod(vm, "sys_Int_shiftr", sys_Int_shiftr);
    fr_registerMethod(vm, "sys_Int_shifta", sys_Int_shifta);
    fr_registerMethod(vm, "sys_Int_pow", sys_Int_pow);
    fr_registerMethod(vm, "sys_Int_toStr", sys_Int_toStr);
    fr_registerMethod(vm, "sys_Int_toHex", sys_Int_toHex);
    fr_registerMethod(vm, "sys_Int_toRadix", sys_Int_toRadix);
    fr_registerMethod(vm, "sys_Int_toChar", sys_Int_toChar);
    fr_registerMethod(vm, "sys_Int_toCode", sys_Int_toCode);
    fr_registerMethod(vm, "sys_Int_static$init", sys_Int_static__init);
    fr_registerMethod(vm, "sys_Void__allocSize__", (fr_NativeFunc)sys_Void__allocSize__);
    fr_registerMethod(vm, "sys_Void_make", sys_Void_make);
    fr_registerMethod(vm, "sys_StrBuf__allocSize__", (fr_NativeFunc)sys_StrBuf__allocSize__);
    fr_registerMethod(vm, "sys_StrBuf_make", sys_StrBuf_make);
    fr_registerMethod(vm, "sys_StrBuf_size", sys_StrBuf_size);
    fr_registerMethod(vm, "sys_StrBuf_capacity", sys_StrBuf_capacity);
    fr_registerMethod(vm, "sys_StrBuf_capacity$1", sys_StrBuf_capacity__1);
    fr_registerMethod(vm, "sys_StrBuf_get", sys_StrBuf_get);
    fr_registerMethod(vm, "sys_StrBuf_getRange", sys_StrBuf_getRange);
    fr_registerMethod(vm, "sys_StrBuf_set", sys_StrBuf_set);
    fr_registerMethod(vm, "sys_StrBuf_addChar", sys_StrBuf_addChar);
    fr_registerMethod(vm, "sys_StrBuf_addStr", sys_StrBuf_addStr);
    fr_registerMethod(vm, "sys_StrBuf_insert", sys_StrBuf_insert);
    fr_registerMethod(vm, "sys_StrBuf_remove", sys_StrBuf_remove);
    fr_registerMethod(vm, "sys_StrBuf_removeRange", sys_StrBuf_removeRange);
    fr_registerMethod(vm, "sys_StrBuf_replaceRange", sys_StrBuf_replaceRange);
    fr_registerMethod(vm, "sys_StrBuf_clear", sys_StrBuf_clear);
    fr_registerMethod(vm, "sys_StrBuf_toStr", sys_StrBuf_toStr);
    fr_registerMethod(vm, "sys_StrBuf_finalize", sys_StrBuf_finalize);
    fr_registerMethod(vm, "sys_Func__allocSize__", (fr_NativeFunc)sys_Func__allocSize__);
    fr_registerMethod(vm, "sys_Func_make", sys_Func_make);
    fr_registerMethod(vm, "sys_Func_arity", sys_Func_arity);
    fr_registerMethod(vm, "sys_Func_callList", sys_Func_callList);
    fr_registerMethod(vm, "sys_Func_callOn", sys_Func_callOn);
    fr_registerMethod(vm, "sys_Func_call", sys_Func_call);
    fr_registerMethod(vm, "sys_Func_bind", sys_Func_bind);
    fr_registerMethod(vm, "sys_Func_enterCtor", sys_Func_enterCtor);
    fr_registerMethod(vm, "sys_Func_exitCtor", sys_Func_exitCtor);
    fr_registerMethod(vm, "sys_Func_checkInCtor", sys_Func_checkInCtor);
    fr_registerMethod(vm, "sys_Func_call$0", sys_Func_call__0);
    fr_registerMethod(vm, "sys_Func_call$1", sys_Func_call__1);
    fr_registerMethod(vm, "sys_Func_call$2", sys_Func_call__2);
    fr_registerMethod(vm, "sys_Func_call$3", sys_Func_call__3);
    fr_registerMethod(vm, "sys_Func_call$4", sys_Func_call__4);
    fr_registerMethod(vm, "sys_Func_call$5", sys_Func_call__5);
    fr_registerMethod(vm, "sys_Func_call$6", sys_Func_call__6);
    fr_registerMethod(vm, "sys_Func_call$7", sys_Func_call__7);
    fr_registerMethod(vm, "sys_Err__allocSize__", (fr_NativeFunc)sys_Err__allocSize__);
    fr_registerMethod(vm, "sys_Err_make", sys_Err_make);
    fr_registerMethod(vm, "sys_Err_msg", sys_Err_msg);
    fr_registerMethod(vm, "sys_Err_cause", sys_Err_cause);
    fr_registerMethod(vm, "sys_Err_trace", sys_Err_trace);
    fr_registerMethod(vm, "sys_Err_traceToStr", sys_Err_traceToStr);
    fr_registerMethod(vm, "sys_Err_toStr", sys_Err_toStr);
    fr_registerMethod(vm, "sys_Str__allocSize__", (fr_NativeFunc)sys_Str__allocSize__);
    fr_registerMethod(vm, "sys_Str_privateMake", sys_Str_privateMake);
    fr_registerMethod(vm, "sys_Str_fromChars", sys_Str_fromChars);
    fr_registerMethod(vm, "sys_Str_hash", sys_Str_hash);
    fr_registerMethod(vm, "sys_Str_size", sys_Str_size);
    fr_registerMethod(vm, "sys_Str_intern", sys_Str_intern);
    fr_registerMethod(vm, "sys_Str_find", sys_Str_find);
    fr_registerMethod(vm, "sys_Str_findr", sys_Str_findr);
    fr_registerMethod(vm, "sys_Str_get", sys_Str_get);
    fr_registerMethod(vm, "sys_Str_getRange", sys_Str_getRange);
    fr_registerMethod(vm, "sys_Str_plus", sys_Str_plus);
    fr_registerMethod(vm, "sys_Str_chars", sys_Str_chars);
    fr_registerMethod(vm, "sys_Str_toUtf8", sys_Str_toUtf8);
    fr_registerMethod(vm, "sys_Str_fromUtf8", sys_Str_fromUtf8);
    fr_registerMethod(vm, "sys_Str_finalize", sys_Str_finalize);
    fr_registerMethod(vm, "sys_Str_format", sys_Str_format);
    fr_registerMethod(vm, "sys_Str_static$init", sys_Str_static__init);
    fr_registerMethod(vm, "sys_Bool__allocSize__", (fr_NativeFunc)sys_Bool__allocSize__);
    fr_registerMethod(vm, "sys_Bool_privateMake", sys_Bool_privateMake);
    fr_registerMethod(vm, "sys_Bool_equals", sys_Bool_equals);
    fr_registerMethod(vm, "sys_Bool_not", sys_Bool_not);
    fr_registerMethod(vm, "sys_Bool_and", sys_Bool_and);
    fr_registerMethod(vm, "sys_Bool_or", sys_Bool_or);
    fr_registerMethod(vm, "sys_Bool_xor", sys_Bool_xor);
    fr_registerMethod(vm, "sys_Bool_static$init", sys_Bool_static__init);
    fr_registerMethod(vm, "sys_ObjArray__allocSize__", (fr_NativeFunc)sys_ObjArray__allocSize__);
    fr_registerMethod(vm, "sys_ObjArray_make", sys_ObjArray_make);
    fr_registerMethod(vm, "sys_ObjArray_get", sys_ObjArray_get);
    fr_registerMethod(vm, "sys_ObjArray_set", sys_ObjArray_set);
    fr_registerMethod(vm, "sys_ObjArray_size", sys_ObjArray_size);
    fr_registerMethod(vm, "sys_ObjArray_realloc", sys_ObjArray_realloc);
    fr_registerMethod(vm, "sys_ObjArray_fill", sys_ObjArray_fill);
    fr_registerMethod(vm, "sys_ObjArray_copyFrom", sys_ObjArray_copyFrom);
    fr_registerMethod(vm, "sys_ObjArray_finalize", sys_ObjArray_finalize);
    fr_registerMethod(vm, "sys_ObjArray_fromJava", sys_ObjArray_fromJava);
    fr_registerMethod(vm, "sys_ObjArray_toJava", sys_ObjArray_toJava);
    fr_registerMethod(vm, "sys_ByteArray__allocSize__", (fr_NativeFunc)sys_ByteArray__allocSize__);
    fr_registerMethod(vm, "sys_ByteArray_make", sys_ByteArray_make);
    fr_registerMethod(vm, "sys_ByteArray_get", sys_ByteArray_get);
    fr_registerMethod(vm, "sys_ByteArray_set", sys_ByteArray_set);
    fr_registerMethod(vm, "sys_ByteArray_size", sys_ByteArray_size);
    fr_registerMethod(vm, "sys_ByteArray_realloc", sys_ByteArray_realloc);
    fr_registerMethod(vm, "sys_ByteArray_fill", sys_ByteArray_fill);
    fr_registerMethod(vm, "sys_ByteArray_copyFrom", sys_ByteArray_copyFrom);
    fr_registerMethod(vm, "sys_ByteArray_finalize", sys_ByteArray_finalize);
    fr_registerMethod(vm, "sys_Float__allocSize__", (fr_NativeFunc)sys_Float__allocSize__);
    fr_registerMethod(vm, "sys_Float_makeBits", sys_Float_makeBits);
    fr_registerMethod(vm, "sys_Float_makeBits32", sys_Float_makeBits32);
    fr_registerMethod(vm, "sys_Float_fromStr", sys_Float_fromStr);
    fr_registerMethod(vm, "sys_Float_random", sys_Float_random);
    fr_registerMethod(vm, "sys_Float_privateMake", sys_Float_privateMake);
    fr_registerMethod(vm, "sys_Float_equals", sys_Float_equals);
    fr_registerMethod(vm, "sys_Float_isNaN", sys_Float_isNaN);
    fr_registerMethod(vm, "sys_Float_negate", sys_Float_negate);
    fr_registerMethod(vm, "sys_Float_mult", sys_Float_mult);
    fr_registerMethod(vm, "sys_Float_multInt", sys_Float_multInt);
    fr_registerMethod(vm, "sys_Float_div", sys_Float_div);
    fr_registerMethod(vm, "sys_Float_divInt", sys_Float_divInt);
    fr_registerMethod(vm, "sys_Float_mod", sys_Float_mod);
    fr_registerMethod(vm, "sys_Float_modInt", sys_Float_modInt);
    fr_registerMethod(vm, "sys_Float_plus", sys_Float_plus);
    fr_registerMethod(vm, "sys_Float_plusInt", sys_Float_plusInt);
    fr_registerMethod(vm, "sys_Float_minus", sys_Float_minus);
    fr_registerMethod(vm, "sys_Float_minusInt", sys_Float_minusInt);
    fr_registerMethod(vm, "sys_Float_bits", sys_Float_bits);
    fr_registerMethod(vm, "sys_Float_bits32", sys_Float_bits32);
    fr_registerMethod(vm, "sys_Float_toStr", sys_Float_toStr);
    fr_registerMethod(vm, "sys_Float_toLocale", sys_Float_toLocale);
    fr_registerMethod(vm, "sys_Float_static$init", sys_Float_static__init);
    fr_registerMethod(vm, "sys_Type__allocSize__", (fr_NativeFunc)sys_Type__allocSize__);
    fr_registerMethod(vm, "sys_Type_privateMake", sys_Type_privateMake);
    fr_registerMethod(vm, "sys_Type_of", sys_Type_of);
    fr_registerMethod(vm, "sys_Type_find", sys_Type_find);
    fr_registerMethod(vm, "sys_Type_name", sys_Type_name);
    fr_registerMethod(vm, "sys_Type_qname", sys_Type_qname);
    fr_registerMethod(vm, "sys_Type_signature", sys_Type_signature);
    fr_registerMethod(vm, "sys_Type_base", sys_Type_base);
    fr_registerMethod(vm, "sys_Type_mixins", sys_Type_mixins);
    fr_registerMethod(vm, "sys_Type_inheritance", sys_Type_inheritance);
    fr_registerMethod(vm, "sys_Type_fits", sys_Type_fits);
    fr_registerMethod(vm, "sys_Type_isVal", sys_Type_isVal);
    fr_registerMethod(vm, "sys_Type_isNullable", sys_Type_isNullable);
    fr_registerMethod(vm, "sys_Type_toNullable", sys_Type_toNullable);
    fr_registerMethod(vm, "sys_Type_toNonNullable", sys_Type_toNonNullable);
    fr_registerMethod(vm, "sys_Type_emptyList", sys_Type_emptyList);
    fr_registerMethod(vm, "sys_Type_isAbstract", sys_Type_isAbstract);
    fr_registerMethod(vm, "sys_Type_isClass", sys_Type_isClass);
    fr_registerMethod(vm, "sys_Type_isConst", sys_Type_isConst);
    fr_registerMethod(vm, "sys_Type_isEnum", sys_Type_isEnum);
    fr_registerMethod(vm, "sys_Type_isFacet", sys_Type_isFacet);
    fr_registerMethod(vm, "sys_Type_isFinal", sys_Type_isFinal);
    fr_registerMethod(vm, "sys_Type_isInternal", sys_Type_isInternal);
    fr_registerMethod(vm, "sys_Type_isMixin", sys_Type_isMixin);
    fr_registerMethod(vm, "sys_Type_isPublic", sys_Type_isPublic);
    fr_registerMethod(vm, "sys_Type_isSynthetic", sys_Type_isSynthetic);
    fr_registerMethod(vm, "sys_Type_toStr", sys_Type_toStr);
    fr_registerMethod(vm, "sys_Type_isJava", sys_Type_isJava);
    fr_registerMethod(vm, "sys_Enum_doFromStr", sys_Enum_doFromStr);
}
