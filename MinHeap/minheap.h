#ifndef __minheap_h__
#define __minheap_h__

#includ <stdlib.h>

typedef struct MinHeap{
  int capacity;
  int no_of_elements;
  int *harr;
}MinHeap;

MinHeap *Minheap_create(int size);

void Miniheapify(MinHeap *heap);
void insertKey(MinHeap *heap, int key);

void DeleteKey(MinHeap *heap, int key);


#define PARENT(i) (i-1/2)
#define LEFT(i) (2*i + 1)
#define RIGHT(i) (2*i + 2)

#define GetMin(A) ((A)->harr[0])
