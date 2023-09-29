#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int id;
    struct node *parent;
    struct node *leftMostChild;
    struct node *rightSibling;
} *nodePointer;

nodePointer make1node(void);
void printNode(nodePointer);
int getDepth(nodePointer);
void printType(nodePointer);
void printChild(nodePointer);
nodePointer init(int);
nodePointer head;

int main(void) {
    int i, j;
    int n;
    int id;
    int k;
    int c1, c2;
    nodePointer p1, p2;
    nodePointer *arr;
    head = init(-1);
    scanf("%d", &n);
    arr = (nodePointer *)malloc(sizeof(nodePointer) * n);
    for (i = 0; i < n; i++)
        arr[i] = init(i);
    for (i = 0; i < n; i++) {
        scanf("%d %d", &id, &k);
        p1 = arr[id];
        for (j = 0; j < k; j++) {
            scanf("%d", &c1);
            p2 = arr[c1];
            p1->leftMostChild = p2;
            p2->parent = p1;
            p1 = p2;
            for (c2 = 1; c2 < j; c2++)
                p1 = p1->rightSibling;
        }
    }
    for (i = 0; i < n; i++)
        printNode(arr[i]);
    free(arr);
    return 0;
}

nodePointer init(int id) {
    nodePointer p;
    p = make1node();
    p->id = id;
    p->parent = NULL;
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    return p;
}

void printNode(nodePointer p) {
    printf("node %d: ", p->id);
    if (p->parent != NULL)
        printf("parent = %d, ", p->parent->id);
    else
        printf("parent = -1, ");
    printf("depth = %d, ", getDepth(p));
    printType(p);
    printf(", ");
    printChild(p);
    printf("\n");
}

nodePointer make1node(void) {
    nodePointer p = (nodePointer)malloc(sizeof(struct node));
    return p;
}

int getDepth(nodePointer p) {
    int depth;
    for (depth = 0; p->parent != NULL; p = p->parent)
        depth++;
    return depth;
}

void printType(nodePointer p) {
    if (p->parent == NULL)
        printf("root");
    else if (p->leftMostChild == NULL)
        printf("leaf");
    else
        printf("internal node");
}

void printChild(nodePointer p) {
    printf("[");
    if (p->leftMostChild != NULL) {
        p = p->leftMostChild;
        printf("%d", p->id);
        for (p = p->rightSibling; p != NULL; p = p->rightSibling)
            printf(", %d", p->id);
    }
    printf("]");
}