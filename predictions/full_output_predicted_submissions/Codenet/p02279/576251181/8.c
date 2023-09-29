#include <stdio.h>
#include <stdlib.h>
typedef struct node {
  int id;
  struct node *parent;
  struct node *leftmostChild;
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
  p->left