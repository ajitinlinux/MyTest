#include "darray.h"

//init_max should be set as greater than zero
DArray *DArrayCreate(size_t element_size, size_t init_max){
  DArray *array = (DArray *)malloc(sizeof(DArray));
  if(array == NULL)
    return NULL;
  array->max = init_max;
  array->end = 0;

  array->element_size = element_size;
  array->data = calloc(element_size, sizeof(void *));

  if(array->data == NULL)
    if(array)
      free(array);
    return NULL;

  array->expand_rate = DEFAULT_EXPAND_RATE;

  return array;
}

void DArray_clear(DArray *arr){
  if(arr->element_size > 0){
    for(int i = 0 ; i < arr->element_size ; i++){
      if(arr->data[i] != NULL)
        free(arr->data[i]);
    }
  }
}

void DArray_destroy(DArray *arr){
  if (arr){
    if(arr->data)
      free(arr->data);
    free(arr);
  }
}

static inline int DArray_resize(DArray *arr, int new_size){
  if (new_size < 0)
    return 0;

  arr->max = new_size;

  void *data = realloc(arr->data, arr->max * sizeof(void *));

  if(data == NULL)
    return 0;

  arr->data = data;

  return 1;
}

int DArray_expand(DArray *arr){
  int old_max = arr->max;

  if(!(DArray_resize(arr, arr->max + arr->expand_rate)))
    return 0;

  memset(arr->data + old_max , 0 , arr->expand_rate+1);

  return 1;
}

int DArray_contract(DArray *arr){
  int new_size = arr->end < (int)arr->expand_rate ?
                            (int)arr->expand_rate : arr->end;

  return DArray_expand(arr, new_size);
}

void DArray_destr_clear(DArray *arr){
  DArray_clear(arr);
  DArray_destroy(arr);
}
