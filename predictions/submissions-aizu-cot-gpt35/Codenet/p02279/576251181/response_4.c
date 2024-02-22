#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int id;
  struct node *parent;
  struct node *leftMostChild;
  struct node *rightSibling;
  int depth;
} * nodePointer;

nodePointer make1node(void);
void printNode(nodePointer);
void printChild(nodePointer);

nodePointer init(int);
nodePointer head;

int main(void) {
  int i, j;
  int n;
  int id;
  int k;
  int c1, c2;
  nodePointer p1, p2;
  nodePointer *arr;

  head = init(-1);

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
  p->depth = 0; // Initialize depth as 0
  return p;
}

void printNode(nodePointer p) {
  printf("node %d: ", p->id);
  
  if (p->parent != NULL)
    printf("parent = %d, ", p->parent->id);
  else
    printf("parent = -1, ");
  
  printf("depth = %d, ", p->depth); // Print the pre-calculated depth

  if (p->leftMostChild == NULL)
    printf("leaf");
  else if (p->parent == NULL)
    printf("root");
  else
    printf("internal node");

  printf(", ");
  printChild(p);
  printf("\n");
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

nodePointer make1node(void) {
  nodePointer p = (nodePointer)malloc(sizeof(struct node));
  return p;
}