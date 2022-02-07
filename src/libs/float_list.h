#ifndef FLOAT_LIST_HEADER
#define FLOAT_LIST_HEADER

#include <stdlib.h>

typedef struct _FloatList FloatList;

// Juntando as funções float list
typedef struct
{
    FloatList *(*create)();
    void (*append)(FloatList *, float);
    float (*get)(FloatList *, size_t);
    long (*index)(FloatList *, float);
    float (*remove)(FloatList *, size_t);
    void (*clear)(FloatList *);
    size_t (*length)(FloatList *);
    void (*foreach)(FloatList *, void (*callback)(float, size_t, FloatList *));
} _float_list_namespace;

extern _float_list_namespace const float_list;

#endif