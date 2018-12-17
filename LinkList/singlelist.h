#ifndef __singlelist_h__
#define __singlelist_h__

typedef void (*list_cmp)(void *a , void *b);

typedef struct ListNode{
  void *val;
  struct ListNode *next;
}ListNode;

typedef struct List{
  int count;
  ListNode *head;
}List;

List *ListCreate();

void ListPush(List *list , void *data);
void *Listpop(List *list);

void ListClear(List *list);
void Listdelete(List *list);

#define FOR_EACHLIST(L,N,V) ListNode *_node = NULL;\
                              ListNode *V = NULL;\
                      for(V = _node = L->head; _node != NULL; V=_node= _node->N)

#define LIST_COUNT(A) ((A)->count)

void ListInsertAtHead(List *list, void *data);
void ListInsertAtNth(List *list, void *data, int n);

void *ListDeleteAtHead(List *list);
void *ListDeleteAtNth(List *list, int n);
void *ListDeleteNode(List *list, ListNode *node);

void *ListRemove(List *list, int n, ListNode *node);

#endif
