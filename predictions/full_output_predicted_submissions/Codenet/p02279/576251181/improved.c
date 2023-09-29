#include <stdio.h>
#include <stdlib.h>
typedef struct node {
  int id;
  struct node *parent;
  struct node *leftMostChild;
  struct node *rightSibling;
} * nodePointer;
nodePointer init(int);
nodePointer make1node(void);
void printNode(nodePointer);
int getDepth(nodePointer);
void printType(nodePointer);
void printChild(nodePointer);
int main(void) {
  int i, j;
  int n;
  int id;
  int k;
  int c1, c2;
  nodePointer *arr;
  scanf("%d", &n);
  arr = (nodePointer *)malloc(sizeof(nodePointer) * n);
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
nodePointer init(int id) {
  nodePointer p;
  p = make1node();
  p->id = id;
  p->parent = NULL;
  p->leftMostChild = NULL;
  p->rightSibling = NULL;
  return p;
}
nodePointer make1node(void) {
  nodePointer p = (nodePointer)malloc(sizeof(struct node));
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
int getDepth(nodePointer p) {
  if (p->parent == NULL)
    return 0;
  return 1 + getDepth(p->parent);
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
    for (; p->rightSibling != NULL; p = p->rightSibling)
      printf(", %d", p->rightSibling->id);
  }
  printf("]");
}
