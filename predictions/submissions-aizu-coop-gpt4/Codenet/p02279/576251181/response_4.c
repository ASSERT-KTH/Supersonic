#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int id;
  int depth;
  struct node *parent;
  struct node *leftMostChild;
  struct node *rightSibling;
} * nodePointer;

nodePointer make1node(void);
void printNode(nodePointer);
void printType(nodePointer);
void printChild(nodePointer);
nodePointer init(int);
void freeTree(nodePointer);
nodePointer head;

int main(void) {
  int i, j, n, id, k, c1, c2;
  nodePointer p1, p2;
  
  scanf("%d", &n);
  
  head = init(-1);
  
  for (i = 0; i < n; i++) {
    scanf("%d%d", &id, &k);
    p1 = init(id);
    p1->depth = (id == 0) ? 0 : head->depth + 1;
    
    if (id != 0) head->rightSibling = p1;
    
    for (j = 0; j < k; j++) {
      scanf("%d", &c1);
      p2 = init(c1);
      p2->depth = p1->depth + 1;
      
      if (j == 0) p1->leftMostChild = p2;
      else p2->parent = p1;
      
      p1 = p2;
    }
    
    printNode(head);
    head = head->rightSibling;
  }
  
  freeTree(head);
  
  return 0;
}

nodePointer init(int id) {
  nodePointer p = make1node();
  p->id = id;
  p->depth = 0;
  p->parent = NULL;
  p->leftMostChild = NULL;
  p->rightSibling = NULL;
  return p;
}

void printNode(nodePointer p) {
  printf("node %d: parent = %d, depth = %d, ", p->id, (p->parent) ? p->parent->id : -1, p->depth);
  printType(p);
  printf(", ");
  printChild(p);
  printf("\n");
}

nodePointer make1node(void) {
  nodePointer p = (nodePointer)malloc(sizeof(struct node));
  return p;
}

void printType(nodePointer p) {
  if (p->parent == NULL) printf("root");
  else if (p->leftMostChild == NULL) printf("leaf");
  else printf("internal node");
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

void freeTree(nodePointer p) {
  if (p == NULL) return;
  freeTree(p->leftMostChild);
  freeTree(p->rightSibling);
  free(p);
}