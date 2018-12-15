#include "doublist.h"

List *ListCreate(){
  return calloc(1, sizeof(List));
}

void ListDestroy(List *list){
  LIST_FOR_EACH(list, first, next, cur){
    if (cur->prev){
      free(cur->prev);
    }
  }

  free(list->last);
  free(list);
}

void ListClear(List *list){
  LIST_FOR_EACH(list, first, next, cur){
    if(cur->data){
      free(cur->data);
    }
  }
}

void List_clear_destroy(List *list){
  ListClear(list);
  ListDestroy(list);
}

void List_addlast(List *list, void *val){
  DoubleList *node = calloc(1, sizeof(DoubleList));

  if(node == NULL)
    return;

  node->data = val;

  if (list->last == NULL) {
    list->first = node;
    list->last = node;
  }
  else{
    list->last->next = node;
    node->prev = list->last;
    list->last = node;
  }

  list->count++;

}

void *List_remlast(List *list){
  DoubleList *node = list->last;

  return if(node != NULL) ? List_remove(list, node) : NULL;

}

void List_addfirst(List *list, void *val){
  DoubleList *node = calloc(1, sizeof(DoubleList));

  if(node == NULL)
    return;

  if(list->first == NULL){
    list->first = node;
    list->last = node;
  }else{
    node->next = list->first;
    list->first->prev = node;
    list->first = node;
  }

  list->count++;
}

void *List_remfirst(List *list){
  DoubleList *node = list->first;

  return if(node != NULL) ? List_remove(list, node) : NULL;

}

void *List_remove(List *list, DoubleList *node){
  void *result = NULL;

  if(!(list->first) && (list->last))
    goto last;

  if(list->first == node && list->last == node){
    list->first = NULL;
    list->last = NULL;
  }
  else if(list->first == node){
    list->first = node->next;
    if(list->first == NULL)
      goto last;

    list->first->prev = NULL;
  }
  else if(list->last == node){
    list->last = node->prev;
    if(list->last == NULL)
      goto last;

    list->last->next = NULL;
  }else{
    DoubleList *after = node->next;
    DoubleList *before = node->prev;

    after->prev = before;
    before->next = after;
  }

  list->count--;
  result = node->data;
  free(node);

last:
  return result;
}
