#include <stdio.h>
#include <stdlib.h>

struct node {
    int id;
    struct node* parent;
    struct node* leftMostChild;
    struct node* rightSibling;
    int depth;
    int numChildren;
};

void printNode(struct node*);
struct node* init(int);
void printChild(struct node*);

struct node* head;

int main(void) {
    int i, j;
    int n;
    int id;
    int k;
    int c1, c2;
    struct node** arr;

    head = init(-1);

    scanf("%d", &n);
    arr = (struct node**)malloc(sizeof(struct node*) * n);

    for (i = 0; i < n; i++)
        arr[i] = init(i);

    for (i = 0; i < n; i++) {
        scanf("%d", &id);
        scanf("%d", &k);
        for (j = 0; j < k; j++) {
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

    for (i = 0; i < n; i++)
        printNode(arr[i]);

    return 0;
}

struct node* init(int id) {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->id = id;
    p->parent = NULL;
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    p->depth = 0;
    p->numChildren = 0;

    if (id != -1) {
        p->depth = p->parent->depth + 1;
        p->parent->numChildren++;
    }

    return p;
}

void printNode(struct node* p) {
    printf("node %d: ", p->id);
    if (p->parent != NULL)
        printf("parent = %d, ", p->parent->id);
    else
        printf("parent = -1, ");
    printf("depth = %d, ", p->depth);

    if (p->parent == NULL)
        printf("root");
    else if (p->leftMostChild == NULL)
        printf("leaf");
    else
        printf("internal node");

    printf(", ");
    printChild(p);
    printf("\n");
}

void printChild(struct node* p) {
    printf("[");
    if (p->leftMostChild != NULL) {
        struct node* child = p->leftMostChild;
        printf("%d", child->id);
        for (int i = 1; i < p->numChildren; i++) {
            printf(", %d", child->rightSibling->id);
            child = child->rightSibling;
        }
    }
    printf("]");
}