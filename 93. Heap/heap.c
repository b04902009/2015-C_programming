#include <stdio.h>
#include "heap.h"
void initialize(struct Heap *heap){
	heap->num = 0;
}
int removeMin(struct Heap *heap){
	int min = 2147483647, min_i;
	for(int i = 0; i < heap->num; i++)
		if(heap->ary[i] < min){
			min = heap->ary[i];
			min_i = i;
		}
	(heap->num)--;
	for(int i = min_i; i < heap->num; i++)  heap->ary[i] = heap->ary[i+1];
	return min;
}
void add(struct Heap *heap, int i){
	heap->ary[heap->num] = i;
	(heap->num)++;
}
int isFull(struct Heap *heap){
	if(heap->num == MAXHEAP)  return 1;
	return 0;
}
int isEmpty(struct Heap *heap){
	if(heap->num == 0)  return 1;
	return 0;
}