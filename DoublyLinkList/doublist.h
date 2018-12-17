#ifndef __doublist_h__
#define __doublist_h__
#include <stdlib.h>

/* TODO :
Test cases
sorting function
*/

typedef struct DoubleList{
  void * data;
  struct DoubleList *next;
  struct DoubleList *prev;
}DoubleList;

typedef struct List{
  int count;
  DoubleList *first;
  DoubleList *last;
}List;

List *ListCreate();

void ListDestroy(List *list);
void ListClear(List *list);
void List_clear_destroy(List *list);

#define List_count(A) ((A)->count)
#define List_first(A) ((A)->first != NULL ? (A)->first->data : NULL)
#define List_last(A)  ((A)->last != NULL ? (A)->last->data : NULL)

void List_addlast(List *list, void *val);
void *List_remlast(List *list);

void List_addfirst(List *list, void *val);
void *List_remfirst(List *list);
void *List_remove(List *list, DoubleList *node);

#define LIST_FOR_EACH(L,F,N,C) DoubleList *_node = NULL;\
                              DoubleList *C = NULL;\
                            for(C = _node = L->F; _node != NULL; V = _node = _node->N)

#endif
