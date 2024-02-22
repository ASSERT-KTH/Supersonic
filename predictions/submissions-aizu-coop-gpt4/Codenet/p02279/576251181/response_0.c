#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int id;
  int depth;
  struct node *parent;
  struct node *leftMostChild;
  struct node *rightSibling;
} * nodePointer;

nodePointer make1node(int);
void printNode(nodePointer);
void printType(nodePointer);
void printChild(nodePointer);
nodePointer init(int, int);
nodePointer head;
#define MAX_NODES 1000
nodePointer arr[MAX_NODES];

int main(void) {
  int i, j;
  int n;
  int id;
  int k;
  int c1, c2;
  head = init(-1, 0);
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    arr[i] = init(i, -1);
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
      arr[c1]->depth = arr[id]->depth + 1;
      c2 = c1;
    }
  }
  for (i = 0; i < n; i++)
    printNode(arr[i]);
  return 0;
}

nodePointer init(int id, int depth) {
  nodePointer p;
  p = make1node(id);
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
  printf("depth = %d, ", p->depth);
  printType(p);
  printf(", ");
  printChild(p);
  printf("\n");
}

nodePointer make1node(int id) {
  static struct node pool[MAX_NODES];
  static int index = 0;
  return &pool[index++];
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