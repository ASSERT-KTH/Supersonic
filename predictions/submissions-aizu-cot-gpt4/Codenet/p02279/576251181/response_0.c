#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int id;
  int depth; // add depth member
  struct node *parent;
  struct node *leftMostChild;
  struct node *rightSibling;
} * nodePointer;

nodePointer make1node(void);
void printNode(nodePointer);
int getDepth(nodePointer);
void printType(nodePointer);
void printChild(nodePointer);
nodePointer init(int);
nodePointer head;

int main(void) {
  // ... (no change) ...
  
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
      arr[c1]->depth = arr[id]->depth + 1; // set depth
      c2 = c1;
    }
  }
  
  // ... (no change) ...
  
  return 0;
}

nodePointer init(int id) {
  nodePointer p;
  p = make1node();
  p->id = id;
  p->depth = 0; // initialize depth to 0
  p->parent = NULL;
  p->leftMostChild = NULL;
  p->rightSibling = NULL;
  return p;
}

void printNode(nodePointer p) {
  // ... (no change) ...
}

nodePointer make1node(void) {
  // ... (no change) ...
}

int getDepth(nodePointer p) {
  return p->depth; // return stored depth
}

void printType(nodePointer p) {
  // ... (no change) ...
}

void printChild(nodePointer p) {
  // ... (no change) ...
}