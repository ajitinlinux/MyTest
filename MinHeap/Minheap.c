#include "minheap.h"

MinHeap *Minheap_create(int size){
  MinHeap *heap = (MinHeap*)malloc(sizeof(MinHeap));

  heap->capacity = size;
  heap->no_of_elements = 0;
  heap->harr = (void*)malloc(sizeof(void) * size);

  return heap;
}

void Miniheapify(MinHeap *heap, int i){
  int l = LEFT(i);
  int r = RIGHT(i);
  int smallest = i;

  if(l < heap->size && heap->harr[l] < smallest)
    smallest = l;

  if(r < heap->size && heap->harr[r] < smallest)
    smallest = r;

  if(smallest != i){
    swap(&heap->harr[smallest], &heap->harr[i]);
    Miniheapify(smallest);
  }
}

void insertKey(MinHeap *heap, int key){
  if(heap->no_of_elements == heap->capacity){
    return;
  }

  heap->no_of_elements++;
  int i = heap->capacity -1;
  heap->harr[i] = key;

  while (i != 0 && heap->harr[PARENT(i)] > heap->harr[i]){
    swap(&heap->harr[PARENT(i)], &heap->harr[i]);
    i = PARENT(i);
  }
}

static void DecreaseKey(MinHeap *heap, int val,int i){
  heap->harr[i] = val;

  while (i != 0 && heap->harr[PARENT(i)] > heap->harr[i]){
    swap(&heap->harr[PARENT(i)], &heap->harr[i]);
    i = PARENT(i);
  }
}

static int extractMin(MinHeap *heap){
  if(heap->no_of_elements <= 0)
    return INT_MAX;

  if(heap->no_of_elements == 1){
    heap->no_of_elements--;
    return heap->harr[0];
  }

  int root = heap->harr[0];
  heap->harr[0] = harr[heap->capacity-1];
  heap->no_of_elements--;

  Miniheapify(0);

  return root;

}

void DeleteKey(MinHeap *heap, int i){
  DecreaseKey(heap, i, INT_MIN);
  extractMin(heap);
}
