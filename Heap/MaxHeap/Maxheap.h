#ifndef __Maxheap_h__
#define __Maxheap_h__

#include <stdlib.h>

typedef struct MaxHeap{
  int *arr;
  int size;
}MaxHeap;

void create_heap(int size);
void max_heapify(MaxHeap *obj, int i);

void build_max(MaxHeap *obj, i);

#define PARENT(i) (i/2)
#define LEFT(i) (2 * i)
#define RIGHT(i) (2 *i + 1)
