#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int id;
  struct node *parent;
  struct node *leftMostChild;
  struct node *rightSibling;
} *nodePointer;

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

  head = init(-1);
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d", &id);
    scanf("%d", &k);

    nodePointer currentNode = init(id);

    for (j = 0; j < k; j++) {
      scanf("%d", &c1);

      if (j == 0) {
        currentNode->leftMostChild = init(c1);
      } else {
        nodePointer sibling = init(c1);
        currentNode->leftMostChild->rightSibling = sibling;
        currentNode->leftMostChild = sibling;
      }
    }

    currentNode->leftMostChild = NULL;
    printNode(currentNode);
  }

  return 0;
}

nodePointer init(int id) {
  nodePointer p = make1node();
  p->id = id;
  p->parent = NULL;
  p->leftMostChild = NULL;
  p->rightSibling = NULL;
  return p;
}

void printNode(nodePointer p) {
  printf("node %d: ", p->id);

  if (p->parent != NULL)
    printf("parent = %d, ", p->parent->id);
  else
    printf("parent = -1, ");

  int depth = 0;
  nodePointer child = p->leftMostChild;

  while (child != NULL) {
    depth++;
    child = child->rightSibling;
  }

  printf("depth = %d, ", depth);

  if (p->parent == NULL)
    printf("root");
  else if (p->leftMostChild == NULL)
    printf("leaf");
  else
    printf("internal node");

  printf(", [");

  child = p->leftMostChild;

  if (child != NULL) {
    printf("%d", child->id);
    child = child->rightSibling;

    while (child != NULL) {
      printf(", %d", child->id);
      child = child->rightSibling;
    }
  }

  printf("]\n");
}

nodePointer make1node(void) {
  nodePointer p = (nodePointer)malloc(sizeof(struct node));
  return p;
}