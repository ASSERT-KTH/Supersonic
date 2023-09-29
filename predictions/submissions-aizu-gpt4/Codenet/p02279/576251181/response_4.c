#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int id;
    struct node *parent;
    struct node *leftMostChild;
    struct node *rightSibling;
} *nodePointer;

nodePointer init(int);
void printNode(nodePointer);
int getDepth(nodePointer);
void printType(nodePointer);
void printChild(nodePointer);

nodePointer init(int id) {
    nodePointer p = (nodePointer)malloc(sizeof(struct node));
    p->id = id;
    p->parent = NULL;
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    return p;
}

void printNode(nodePointer p) {
    printf("node %d: ", p->id);
    printf("parent = %d, ", p->parent ? p->parent->id : -1);
    printf("depth = %d, ", getDepth(p));
    printType(p);
    printf(", ");
    printChild(p);
    printf("\n");
}

int getDepth(nodePointer p) {
    int depth;
    for (depth = 0; p->parent; p = p->parent, ++depth);
    return depth;
}

void printType(nodePointer p) {
    printf(p->parent == NULL ? "root" : p->leftMostChild == NULL ? "leaf" : "internal node");
}

void printChild(nodePointer p) {
    printf("[");
    if (p->leftMostChild) {
        for (p = p->leftMostChild; p; p = p->rightSibling)
            printf("%d%s", p->id, p->rightSibling ? ", " : "");
    }
    printf("]");
}

int main(void) {
    int n, id, k, c;
    scanf("%d", &n);
    nodePointer *arr = (nodePointer *)malloc(n * sizeof(nodePointer));
    for (int i = 0; i < n; ++i)
        arr[i] = init(i);

    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &id, &k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &c);
            nodePointer *parent = &arr[id];
            if (j == 0) {
                (*parent)->leftMostChild = arr[c];
            } else {
                (*parent)->rightSibling = arr[c];
            }
            arr[c]->parent = *parent;
        }
    }
    for (int i = 0; i < n; ++i)
        printNode(arr[i]);

    free(arr);
    return 0;
}