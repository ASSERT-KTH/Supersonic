#include <stdio.h>
#include <stdlib.h>
typedef struct node {
  int id;
  int depth;  // added depth field
  struct node *parent;
  struct node *leftMostChild;
  struct node *rightSibling;
} * nodePointer;

// Other functions remain the same

nodePointer init(int id) {
  nodePointer p;
  p = make1node();
  p->id = id;
  p->parent = NULL;
  p->leftMostChild = NULL;
  p->rightSibling = NULL;
  p->depth = 0;  // initialize depth to 0
  return p;
}

// In the main function, during tree creation
for (j = 0; j < k; j++) {
  scanf("%d", &c1);
  if (j == 0) {
    arr[id]->leftMostChild = arr[c1];
  } else {
    arr[c2]->rightSibling = arr[c1];
  }
  arr[c1]->parent = arr[id];
  arr[c1]->depth = arr[id]->depth + 1;  // calculate depth
  c2 = c1;
}

// In the printNode function
printf("depth = %d, ", p->depth);  // use stored depth