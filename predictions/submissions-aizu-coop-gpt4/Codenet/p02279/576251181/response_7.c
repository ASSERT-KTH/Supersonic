#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int id;
  int depth;  // added depth field
  struct node *parent;
  struct node *leftMostChild;
  struct node *rightSibling;
} * nodePointer;

// rest of the function declarations...

int main(void) {
  // ...
  for (i = 0; i < n; i++) {
    // ...
    for (j = 0; j < k; j++) {
      // ...
      arr[c1]->parent = arr[id];
      arr[c1]->depth = arr[id]->depth + 1;  // calculate and store depth
      // ...
    }
  }
  // ...
}

// rest of the functions...

int getDepth(nodePointer p) {
  return p->depth;  // return stored depth
}