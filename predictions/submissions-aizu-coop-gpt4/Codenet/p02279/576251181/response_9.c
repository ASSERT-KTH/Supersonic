#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int id;
  int depth; // store depth in node
  struct node *parent;
  struct node *leftMostChild;
  struct node *rightSibling;
} * nodePointer;

nodePointer makeNodes(int n); // allocate memory for all nodes at once
nodePointer init(nodePointer parent, int id); // calculate and store depth during initialization
// ... remaining function declarations ...

int main(void) {
  // ...
  nodePointer *arr = makeNodes(n); // single call to malloc
  for (i = 0; i < n; i++)
    arr[i] = init(head, i); // initialize node with parent
  // ...
}

nodePointer makeNodes(int n) {
  return (nodePointer *)malloc(sizeof(nodePointer) * n);
}

nodePointer init(nodePointer parent, int id) {
  nodePointer p = make1node();
  p->id = id;
  p->parent = parent;
  p->leftMostChild = NULL;
  p->rightSibling = NULL;
  p->depth = parent ? parent->depth + 1 : 0; // calculate depth based on parent's depth
  return p;
}

void printNode(nodePointer p) {
  printf("node %d: ", p->id);
  if (p->parent != NULL)
    printf("parent = %d, ", p->parent->id);
  else
    printf("parent = -1, ");
  printf("depth = %d, ", p->depth); // no need to call getDepth
  // ... remaining printNode code ...
}

// ... remaining function definitions ...