#include "minunit.h"
#include "darry.h"

static DArray *arr = NULL;

static int *val1 = NULL;
static int *val2 = NULL;

char *test_create(){
  arr = DArrayCreate(sizeof(int), 100);

  mu_assert(arr != NULL, "DArray Create Failed.");
  mu_assert(arr->data != NULL, "data is not created.");

  mu_assert(arr->end == 0) , "end is not at the right spot");

  return NULL;
}

char *test_destroy(){
  DArray_destroy();
  return NULL;
}
