#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int id;
  struct node *parent;
  struct node *leftMostChild;
  struct node *rightSibling;
  int *childIds;
  int childCount;
} node;

node* make1node(void);
void printNode(node*);
void printType(node*);
void printChild(node*);
int main(void);

node* make1node(void) {
  node* p = malloc(sizeof(node));
  p->parent = NULL;
  p->leftMostChild = NULL;
  p->rightSibling = NULL;
  p->childIds = NULL;
  p->childCount = 0;
  return p;
}

void printNode(node* p) {
  printf("node %d: ", p->id);
  if (p->parent != NULL)
    printf("parent = %d, ", p->parent->id);
  else
    printf("parent = -1, ");
  printf("depth = %d, ", p->id == -1 ? 0 : p->parent->id == -1 ? 1 : p->parent->depth + 1);
  printType(p);
  printf(", ");
  printChild(p);
  printf("\n");
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
    printf("%d", p->childIds[0]);
    for (int i = 1; i < p->childCount; i++)
      printf(", %d", p->childIds[i]);
  }
  printf("]");
}

int main(void) {
  int i, j;
  int n;
  int id;
  int k;
  int c1, c2;
  node *p1, *p2;
  node **arr;
  node *head = make1node();
  scanf("%d", &n);
  arr = malloc(sizeof(node*) * n);
  for (i = 0; i < n; i++)
    arr[i] = make1node();
  for (i = 0; i < n; i++) {
    scanf("%d", &id);
    scanf("%d", &k);
    arr[id]->id = id;
    arr[id]->childCount = k;
    arr[id]->childIds = malloc(sizeof(int) * k);
    for (j = 0; j < k; j++) {
      scanf("%d", &c1);
      if (j == 0) {
        arr[id]->leftMostChild = arr[c1];
      } else {
        arr[c2]->rightSibling = arr[c1];
      }
      arr[c1]->parent = arr[id];
      arr[id]->childIds[j] = c1;
      c2 = c1;
    }
  }
  for (i = 0; i < n; i++)
    printNode(arr[i]);
  return 0;
}