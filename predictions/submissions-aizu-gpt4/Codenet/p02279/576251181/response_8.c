#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int id;
    struct node *parent;
    struct node *leftMostChild;
    struct node *rightSibling;
} * nodePointer;

nodePointer make1node(void) {
    return (nodePointer)malloc(sizeof(struct node));
}

nodePointer init(int id) {
    nodePointer p = make1node();
    p->id = id;
    p->parent = NULL;
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    return p;
}

int getDepth(nodePointer p) {
    int depth = 0;
    while(p->parent != NULL) {
        p = p->parent;
        ++depth;
    }
    return depth;
}

void printType(nodePointer p) {
    if (!p->parent)
        printf("root");
    else if (!p->leftMostChild)
        printf("leaf");
    else
        printf("internal node");
}

void printChild(nodePointer p) {
    printf("[");
    if (p->leftMostChild) {
        for (p = p->leftMostChild; p != NULL; p = p->rightSibling) {
            printf("%d", p->id);
            if (p->rightSibling != NULL) printf(", ");
        }
    }
    printf("]");
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

int main(void) {
    int n;
    scanf("%d", &n);

    nodePointer *arr = (nodePointer *)malloc(sizeof(nodePointer) * n);
    for (int i = 0; i < n; ++i)
        arr[i] = init(i);

    for (int i = 0; i < n; ++i) {
        int id, k, c1, c2;
        scanf("%d%d", &id, &k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &c1);
            if (j == 0) {
                arr[id]->leftMostChild = arr[c1];
            } else {
                arr[c2]->rightSibling = arr[c1];
            }
            arr[c1]->parent = arr[id];
            c2 = c1;
        }
    }

    for (int i = 0; i < n; ++i)
        printNode(arr[i]);

    free(arr);
    return 0;
}