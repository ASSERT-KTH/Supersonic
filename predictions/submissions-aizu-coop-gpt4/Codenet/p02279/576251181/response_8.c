#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int id;
  int depth;
  struct node *parent;
  struct node *leftMostChild;
  struct node *rightSibling;
} * nodePointer;

nodePointer nodes[2000];

nodePointer init(int id, int depth) {
  nodePointer p = (nodePointer) malloc(sizeof(struct node));
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

int main(void) {
  int i, j;
  int n;
  int id;
  int k;
  int c1, c2;
  nodePointer p1, p2;

  scanf("%d", &n);
  for (i = 0; i < n; i++)
    nodes[i] = init(i, 0);
  for (i = 0; i < n; i++) {
    scanf("%d", &id);
    scanf("%d", &k);
    for (j = 0; j < k; j++) {
      scanf("%d", &c1);
      if (j == 0) {
        nodes[id]->leftMostChild = nodes[c1];
      } else {
        nodes[c2]->rightSibling = nodes[c1];
      }
      nodes[c1]->parent = nodes[id];
      nodes[c1]->depth = nodes[id]->depth + 1;
      c2 = c1;
    }
  }
  for (i = 0; i < n; i++)
    printNode(nodes[i]);
  return 0;
}