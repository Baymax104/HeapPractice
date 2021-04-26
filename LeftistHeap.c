/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/4/20 19:37
*@Version
*/

#include "LeftistHeap.h"
/*int main () {
    Node *root = NULL;
    createHeapLH(&root);
    projectLH(root);
    return 0;
}*/
Node *mergeLH(Node *root1, Node *root2) {
    if (!root1) {
        return root2;
    }
    if (!root2) {
        return root1;
    }
    if (root1->data < root2->data) {
        return mergeOperateLH(root1, root2);
    } else { // root1->data > root2->data
        return mergeOperateLH(root2, root1);
    }
}
void initNodeLH(Node **node) {
    *node = (Node*)malloc(sizeof(Node));
    (*node)->data = 0;
    (*node)->npl = 0;
    (*node)->left = NULL;
    (*node)->right = NULL;
}
Node *mergeOperateLH(Node *root1, Node *root2) {
    if (!root1->left) { // 由于左式堆性质,堆的左子树为空,则该节点为单节点
        root1->left = root2;
    } else { // 该节点不为单节点
        root1->right = mergeLH(root1->right, root2);
        if (root1->left->npl < root1->right->npl) { // 交换左右节点
            Node *temp = root1->left;
            root1->left = root1->right;
            root1->right = temp;
        }
        root1->npl = root1->right->npl + 1;
    }
    return root1;
}
void insertLH(Node **root, int data) {
    Node *temp;
    initNodeLH(&temp);
    temp->data = data;
    *root = mergeLH(*root, temp);
}
void preOrderLH(Node *node) {
    if (node) {
        printf("%d ", node->data);
        preOrderLH(node->left);
        preOrderLH(node->right);
    }
}
void inOrderLH(Node *node) {
    if(node) {
        inOrderLH(node->left);
        printf("%d ", node->data);
        inOrderLH(node->right);
    }
}
void createHeapLH(Node **root) {
    int data;
    printf("请输入数据:(按-1结束输入)\n");
    while (1) {
        scanf("%d", &data);
        if (data == -1) break;
        insertLH(root, data);
    }
}
int delLH(Node **root) {
    Node *left = (*root)->left;
    Node *right = (*root)->right;
    int data = (*root)->data;
    Node *delNode = *root;
    *root = mergeLH(left, right);
    free(delNode);
    return data;
}
void projectLH(Node *root) {
    int op;
    int data;
    do {
        puts("1)添加数据");
        puts("2)删除数据");
        puts("3)前序遍历");
        puts("4)中序遍历");
        puts("5)退出");
        puts("请输入你的选择:");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("请输入添加的数据:\n");
                scanf("%d", &data);
                insertLH(&root, data);
                break;
            case 2:
                printf("弹出数据为:%d\n", delLH(&root));
                break;
            case 3:
                preOrderLH(root);
                printf("\n");
                break;
            case 4:
                inOrderLH(root);
                printf("\n");
                break;
            case 5:
                printf("Goodbye\n");
                return;
            default:
                break;
        }
    } while (1);
}
