#ifndef DYTHONSPLTYPES_H
#define DYTHONSPLTYPES_H

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>
#include <v_copyIn.h>

#include "dythonDcps.h"


extern c_metaObject __dython_dython__load (c_base base);

extern c_metaObject __dython_dython_bit__load (c_base base);

extern const char *dython_bit_KDython_metaDescriptor[];
extern const int dython_bit_KDython_metaDescriptorArrLength;
extern const int dython_bit_KDython_metaDescriptorLength;
extern c_metaObject __dython_bit_KDython__load (c_base base);
struct _dython_bit_KDython ;
extern  v_copyin_result __dython_bit_KDython__copyIn(c_base base, const void *from, void *to);
extern  void __dython_bit_KDython__copyOut(const void *_from, void *_to);
struct _dython_bit_KDython {
    c_string key;
    c_string value;
};

extern const char *dython_bit_Dython_metaDescriptor[];
extern const int dython_bit_Dython_metaDescriptorArrLength;
extern const int dython_bit_Dython_metaDescriptorLength;
extern c_metaObject __dython_bit_Dython__load (c_base base);
struct _dython_bit_Dython ;
extern  v_copyin_result __dython_bit_Dython__copyIn(c_base base, const void *from, void *to);
extern  void __dython_bit_Dython__copyOut(const void *_from, void *_to);
struct _dython_bit_Dython {
    c_string value;
};

#undef OS_API
#endif
