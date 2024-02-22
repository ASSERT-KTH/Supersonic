#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000

typedef struct node {
  int id;
  struct node* parent;
  struct node* leftMostChild;
  struct node* rightSibling;
} node;

void printNode(node* p);
int getDepth(node* p);
void printType(node* p);
void printChild(node* p);

node nodes[MAX_NODES] = {0};
int nodeCount = 0;

node* make1node(void) {
  return &nodes[nodeCount++];
}

node* init(int id) {
  node* p = make1node();
  p->id = id;
  p->parent = NULL;
  p->leftMostChild = NULL;
  p->rightSibling = NULL;
  return p;
}

void printNode(node* p) {
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

int getDepth(node* p) {
  int depth = 0;
  while (p->parent != NULL) {
    p = p->parent;
    depth++;
  }
  return depth;
}

void printType(node* p) {
  if (p->parent == NULL)
    printf("root");
  else if (p->leftMostChild == NULL)
    printf("leaf");
  else
    printf("internal node");
}

void printChild(node* p) {
  printf("[");
  if (p->leftMostChild != NULL) {
    node* child = p->leftMostChild;
    printf("%d", child->id);
    while (child->rightSibling != NULL) {
      child = child->rightSibling;
      printf(", %d", child->id);
    }
  }
  printf("]");
}

int main(void) {
  int i, j;
  int n;
  int id;
  int k;
  int c1, c2;
  node* p1, *p2;

  scanf("%d", &n);

  for (i = 0; i < n; i++)
    nodes[i] = *init(i);

  for (i = 0; i < n; i++) {
    scanf("%d", &id);
    scanf("%d", &k);
    for (j = 0; j < k; j++) {
      scanf("%d", &c1);
      if (j == 0) {
        nodes[id].leftMostChild = &nodes[c1];
      } else {
        nodes[c2].rightSibling = &nodes[c1];
      }
      nodes[c1].parent = &nodes[id];
      c2 = c1;
    }
  }

  for (i = 0; i < n; i++)
    printNode(&nodes[i]);

  return 0;
}