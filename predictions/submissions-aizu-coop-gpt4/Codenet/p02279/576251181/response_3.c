#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int id;
  int depth;  // Add depth field
  struct node *parent;
  struct node *leftMostChild;
  struct node *rightSibling;
} * nodePointer;

nodePointer make1node(void);
void printNode(nodePointer);
void printType(nodePointer);
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
    scanf("%d %d", &id, &k);  // Combine scanf calls
    if (k > 0) {
      scanf("%d", &c1);
      arr[id]->leftMostChild = arr[c1];
      arr[c1]->parent = arr[id];
      arr[c1]->depth = arr[id]->depth + 1;  // Update depth
      for (j = 1; j < k; j++) {
        scanf("%d", &c2);
        arr[c1]->rightSibling = arr[c2];
        arr[c2]->parent = arr[id];
        arr[c2]->depth = arr[id]->depth + 1;  // Update depth
        c1 = c2;
      }
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
  p->depth = 0;  // Initialize depth
  p->parent = NULL;
  p->leftMostChild = NULL;
  p->rightSibling = NULL;
  return p;
}

void printNode(nodePointer p) {
  // Combine printf calls
  printf("node %d: parent = %d, depth = %d, ", p->id, (p->parent != NULL ? p->parent->id : -1), p->depth);
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
    nodePointer temp = p->leftMostChild;  // Use temporary variable
    printf("%d", temp->id);
    while (temp->rightSibling != NULL) {
      temp = temp->rightSibling;
      printf(", %d", temp->id);
    }
  }
  printf("]");
}