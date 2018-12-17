#include "singlelist.h"

List *ListCreate(){

  List *temp = (List*)malloc(sizeof(List));

  temp->count = 0;
  temp->head = NULL;

  return temp;
}

void ListClear(List *list){
  FOR_EACHLIST(list, next , cur){
    if(cur){
      free(cur->val);
    }
  }
}

void ListDelete(List *list){
  ListNode *cur = list->head;
    while(cur != NULL){
      ListNode *temp = cur->next;
      free(cur);
      cur = temp;
  }

  free(list);
}

void ListPush(List *list, void *data){

  ListNode *node = (ListNode*)(sizeof(ListNode));

  if(node == NULL)
    return;

  node->val = data;

  if(list->head == NULL)
    list->head = node;
  else{
    ListNode *temp = list->head;

    while(temp->next != NULL)
      temp = temp->next;

    temp->next = node;
  }

  list->count++;

}

void *Listpop(List *list){
  return if (list->head != NULL)? ListRemove(list, list->count, NULL) : NULL;
}

void *ListDeleteAtHead(List *list){
  return if (list->head != NULL)? ListRemove(list, 1, NULL) : NULL;
}

void *ListDeleteNode(List *list, ListNode *node){
  return if (list->head != NULL)? ListRemove(list , 0, node) : NULL;
}

void ListRemove(List *list, int n, ListNode *node){
  void *result = NULL;

  if(!list->head)
    goto last;

  if(node != NULL){
    if(list->head == node){
      list->head = node->next;
    }
    else{
      ListNode *temp = list->head;
      while(temp != NULL && temp->next != node){
        temp = temp->next;
      }

      if(temp != NULL){
        temp->next = node->next;
      }else{
        goto last;
      }

      list->count--;
      result = node->val;
      free(node);
      goto last;
    }
  }
  else{
    if (n == 1){
      ListNode *temp = list->head;
      list->head = temp->next;
      result = temp->data;
      free(temp);
      goto last;
    }else{
      ListNode *temp = list->head;
      for (int i = 1 ; i < n-1 && temp != NULL ;i++)
        temp = temp->next;

      if(temp != NULL){
        ListNode *del = temp->next;
        temp->next = del->next;
        result = del->val;
        free(del);
        goto last;
      }
    }
  }
  last:
    return result;
}

void ListInsertAtHead(List *list , void *data){
  ListNode *node = (ListNode*)malloc(sizeof(ListNode));

  if(node == NULL)
    return;

  node->val = data;
  node->next = NULL;
  if(list->head == NULL){
    list->head = node;
  }
  else{
    node->next = list->head;
    list->head = node;
  }

  list->count++;
}

void ListInsertAtNth(List *list , void *data, int n){
  if (n > list->count)
    return;

  ListNode *node = (ListNode*)malloc(sizeof(ListNode));

  if(node == NULL)
    return;

  node->val = data;

  if (n == 1){
    if(list->head == NULL)
      list->head = node;
    else{
      node->next = list->head;
      list->head = node;
    }
    list->count++;
    return;
  }

  ListNode *temp = list->head;

  for (int i = 1 ; i < n-1 && temp != NULL ; i++)
    temp = temp->next;

  node->next = temp->next;
  temp->next = node;

  list->count++;
}
