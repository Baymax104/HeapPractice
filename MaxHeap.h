/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/8 21:35
*@Version
*/

#ifndef HEAP_MAXHEAP_H
#define HEAP_MAXHEAP_H

#include <stdio.h>// 最大堆
#include"stdlib.h"
#define SIZE 10

typedef struct heap {
    int *data;
    int size;
}Heap;

void initHeap(Heap **heap);
void swap(int *x, int *y);
void push(Heap *heap, int data);
int pop(Heap *heap);
void shiftUp(Heap *heap);
void shiftDown(Heap *heap);
void project(Heap *heap);
void listHeap(Heap *heap);
void createHeap(Heap *heap);

#endif //HEAP_MAXHEAP_H
