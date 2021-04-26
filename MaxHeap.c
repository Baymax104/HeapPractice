/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/8 21:37
*@Version
*/
#include "MaxHeap.h"
//int main() {
//    Heap *heap = NULL;
//    initHeap(&heap);
//    createHeap(heap);
//    project(heap);
//    return 0;
//}
void initHeap(Heap **heap) {
    *heap = (Heap*)malloc(sizeof(Heap));
    (*heap)->data = (int*)malloc(sizeof(int) * SIZE);
    (*heap)->size = -1;
}
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void push(Heap *heap, int data) {
    if (heap->size == SIZE - 1) {
        printf("堆已满!\n");
        return;
    }
    heap->size++;
    heap->data[heap->size] = data;
    shiftUp(heap);
}
void shiftUp(Heap *heap) {
    int data = heap->data[heap->size];
    for (int i = heap->size; heap->data[(i - 1) / 2] < data && i != 0; i = (i - 1) / 2) {
        swap(&heap->data[i], &heap->data[(i - 1) / 2]);
    }
}
int pop(Heap *heap) {
    if (heap->size == -1) {
        printf("堆为空!\n");
        return -1;
    }
    int popData = heap->data[0];
    heap->data[0] = heap->data[heap->size];
    heap->size--;
    shiftDown(heap);
    return popData;
}
void shiftDown(Heap *heap) {
    int parent = 0;
    int child = parent * 2 + 1;
    while (child <= heap->size) {
        // 若右节点比左节点大,则child移至右节点
        if (child + 1 <= heap->size && heap->data[child + 1] > heap->data[child]) {
            child = child + 1;
        }
        if (heap->data[parent] < heap->data[child]) {
            swap(&heap->data[parent], &heap->data[child]);
        } else {
            break;
        }
        parent = child;
        child = parent * 2 + 1;
    }
}
void listHeap(Heap *heap) {
    for (int i = 0; i <= heap->size; i++) {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
}
void createHeap(Heap *heap) {
    int data;
    printf("请输入数据:(按-1结束输入)\n");
    while (1) {
        scanf("%d", &data);
        if (data == -1) {
            break;
        }
        push(heap, data);
    }
}
void project(Heap *heap) {
    int op;
    int data;
    do {
        puts("1)添加数据");
        puts("2)删除数据");
        puts("3)查看堆");
        puts("4)退出");
        puts("请输入你的选择:");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("添加的数据:\n");
                scanf("%d", &data);
                push(heap, data);
                listHeap(heap);
                break;
            case 2:
                printf("弹出数据为:%d\n", pop(heap));
                listHeap(heap);
                break;
            case 3:
                listHeap(heap);
                break;
            case 4:
                printf("Goodbye\n");
                return;
            default:
                break;
        }
    } while (1);
}

