#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int id;
  int depth;
  struct node *parent;
  struct node *leftMostChild;
  struct node *rightSibling;
} * nodePointer;

nodePointer make1node(int, int);
void printNode(nodePointer);
void printType(nodePointer);
void printChild(nodePointer);

nodePointer head;

int main(void) {
  int i, j;
  int n;
  int id;
  int k;
  int c1, c2;
  nodePointer p1, p2;
  nodePointer *arr;
  head = make1node(-1, -1);
  scanf("%d", &n);
  arr = (nodePointer *)malloc(sizeof(nodePointer) * n);
  for (i = 0; i < n; i++)
    arr[i] = make1node(i, i==0?-1:0); //assign depth here
  for (i = 0; i < n; i++) {
    scanf("%d", &id);
    scanf("%d", &k);
    for (j = 0; j < k; j++) {
      scanf("%d", &c1);
      arr[c1]->depth = arr[id]->depth + 1; //update depth here
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
  free(arr); //free memory
  return 0;
}

nodePointer make1node(int id, int depth) {
  nodePointer p = (nodePointer)malloc(sizeof(struct node));
  p->id = id;
  p->depth = depth;
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
  printf("depth = %d, ", p->depth); //use stored depth
  printType(p);
  printf(", ");
  printChild(p);
  printf("\n");
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