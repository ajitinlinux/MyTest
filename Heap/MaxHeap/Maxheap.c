#include "Maxheap.h"


static void swap(int *i, int *j){
  int temp = *i;
  *i = *j
  *j = temp;
}
static void create_heap(int size){
  MaxHeap *obj = (MaxHeap*)malloc(sizeof(MaxHeap));

  obj->size = size;
  obj->arr = (int*)malloc(sizeof(int) * size);

  return obj;
}

void max_heapify(MaxHeap *obj, int i){
  int left = LEFT(i);
  int right = RIGHT(i);

  int largest = i;

  if(left <= obj->size && obj->arr[left] > obj->arr[i])
    largest = left;

  if(right <= obj->size && obj->arr[right] > obj->arr[largest])
    largest = right;

  if(largest != i){
    swap(&obj->arr[i], &obj->arr[largest]);
    max_heapify(obj, largest);
  }
}

void build_max(MaxHeap *obj, int *Arr, int size){
  create_heap(size);
  int i;
  for(i = 0 ; i < size ; i++)
    obj->arr[i] = Arr[i];
    
  for(i = obj->size/2 ; i >= 1 ; i--)
    max_heapify(obj, i);
}
