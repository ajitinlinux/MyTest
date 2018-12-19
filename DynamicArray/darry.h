#ifndef __darray_h__
#define __darray_h__
#include <stdlib.h>

typedef struct DArray{
  int end;
  int max;
  size_t element_size;
  size_t expand_rate;

  void **data;
}DArray;

#define DEFAULT_EXPAND_RATE 300

DArray *DArrayCreate(size_t element_size , size_t init_max);

void DArray_destroy(DArray *arr);

void DArray_clear(DArray *arr);

void DArray_destr_clear(DArray *arr);

int DArray_expand(DArray *arr);

int DArray_contract(DArray *arr);

int DArray_push(DArray *arr, void *val);

void *DArray_pop(DArray *arr);

#define DArray_end(A) ((A)->end)
#define DArray_last(A) ((A)->data[(A)->end-1])
#define DArray_first(A) ((A)->data[0])
#define DArray_count(A) DArray_end(A)
#define DArray_max(A) ((A)->max)
#define DArray_free(A) free((A))

static inline void DArray_set(DArray *arr, int i, void *val){
  if (i > arr->max)
    return;

  if (i > arr->end)
    arr->end = i;

  arr->data[i] = val;
}

static inline void *DArray_get(DArray *arr, int i){
  if( i > arr->max)
    return NULL;

  return arr->data[i];
}

static inline void *DArray_remove(DArray *arr, int i){
  if(i > arr->max)
    return NULL;

  void *val = arr->data[i];
  arr->data[i] = NULL;
  return val;
}

static inline void DArray_new(DArray *arr){
  if (arr->element_size < 0)
    return;

  return calloc(1, arr->element_size);
}

#endif
