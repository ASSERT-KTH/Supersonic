#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int id;
  struct node *parent;
  struct node *leftMostChild;
  struct node *rightSibling;
  int depth;
  int type;
  int childCount;
  int *childIds;
} * nodePointer;

nodePointer make1node(void);
void printNode(nodePointer);
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

  for (i = 0; i < n; i++) {
    arr[i] = (nodePointer)malloc(sizeof(struct node));
    arr[i]->id = i;
    arr[i]->parent = NULL;
    arr[i]->leftMostChild = NULL;
    arr[i]->rightSibling = NULL;
    arr[i]->depth = 0;
    arr[i]->type = -1;
    arr[i]->childCount = 0;
    arr[i]->childIds = NULL;
  }

  for (i = 0; i < n; i++) {
    scanf("%d", &id);
    scanf("%d", &k);

    if (k > 0) {
      arr[id]->type = 2; // internal node
      arr[id]->childCount = k;
      arr[id]->childIds = (int *)malloc(sizeof(int) * k);
    } else {
      arr[id]->type = 1; // leaf node
    }

    for (j = 0; j < k; j++) {
      scanf("%d", &c1);

      if (j == 0) {
        arr[id]->leftMostChild = arr[c1];
      } else {
        arr[c2]->rightSibling = arr[c1];
      }

      arr[c1]->parent = arr[id];
      arr[c1]->depth = arr[id]->depth + 1;
      arr[id]->childIds[j] = c1;

      c2 = c1;
    }
  }

  for (i = 0; i < n; i++) {
    printNode(arr[i]);
  }

  // Free allocated memory
  for (i = 0; i < n; i++) {
    if (arr[i]->childCount > 0) {
      free(arr[i]->childIds);
    }
    free(arr[i]);
  }
  free(arr);

  return 0;
}

nodePointer init(int id) {
  nodePointer p = (nodePointer)malloc(sizeof(struct node));
  p->id = id;
  p->parent = NULL;
  p->leftMostChild = NULL;
  p->rightSibling = NULL;
  p->depth = 0;
  p->type = 0;
  p->childCount = 0;
  p->childIds = NULL;
  return p;
}

void printNode(nodePointer p) {
  printf("node %d: parent = %d, depth = %d, ", p->id, (p->parent != NULL ? p->parent->id : -1), p->depth);

  if (p->type == 0) {
    printf("root");
  } else if (p->type == 1) {
    printf("leaf");
  } else if (p->type == 2) {
    printf("internal node");
  }

  printf(", [");

  if (p->childCount > 0) {
    printf("%d", p->childIds[0]);
    for (int i = 1; i < p->childCount; i++) {
      printf(", %d", p->childIds[i]);
    }
  }

  printf("]\n");
}