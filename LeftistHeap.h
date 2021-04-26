/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/20 19:37
*@Version
*/

#ifndef HEAP_LEFTISTHEAP_H
#define HEAP_LEFTISTHEAP_H

#include"stdio.h"
#include"stdlib.h"
typedef struct nodeLH {
    int data;
    int npl;
    struct nodeLH *left;
    struct nodeLH *right;
}Node;
Node *mergeLH(Node *root1, Node *root2);
Node *mergeOperateLH(Node *root1, Node *root2);
void initNodeLH(Node **node);
void insertLH(Node **root, int data);
void preOrderLH(Node *node);
void inOrderLH(Node *node);
void createHeapLH(Node **root);
int delLH(Node **root);
void projectLH(Node *root);

#endif //HEAP_LEFTISTHEAP_H
