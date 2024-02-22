#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int id;
  struct node* parent;
  struct node* leftMostChild;
  struct node* rightSibling;
} Node;

Node* init(int id);
void printNode(Node* p);
void printType(Node* p);
void printChild(Node* p);

Node* head;
Node arr[100000];

int main() {
  int n;
  scanf("%d", &n);

  head = init(-1);

  for (int i = 0; i < n; i++)
    arr[i] = *init(i);

  for (int i = 0; i < n; i++) {
    int id, k;
    scanf("%d %d", &id, &k);

    Node* parent = &arr[id];

    for (int j = 0; j < k; j++) {
      int childId;
      scanf("%d", &childId);

      Node* child = &arr[childId];
      child->parent = parent;

      if (j == 0) {
        parent->leftMostChild = child;
      } else {
        Node* sibling = parent->leftMostChild;
        while (sibling->rightSibling) {
          sibling = sibling->rightSibling;
        }
        sibling->rightSibling = child;
      }
    }
  }

  for (int i = 0; i < n; i++)
    printNode(&arr[i]);

  return 0;
}

Node* init(int id) {
  Node* p = (Node*)malloc(sizeof(Node));
  p->id = id;
  p->parent = NULL;
  p->leftMostChild = NULL;
  p->rightSibling = NULL;
  return p;
}

void printNode(Node* p) {
  printf("node %d: ", p->id);

  if (p->parent) {
    printf("parent = %d, ", p->parent->id);
  } else {
    printf("parent = -1, ");
  }

  int depth = 0;
  Node* current = p;
  while (current->parent) {
    depth++;
    current = current->parent;
  }
  printf("depth = %d, ", depth);

  printType(p);
  printf(", ");
  printChild(p);
  printf("\n");
}

void printType(Node* p) {
  if (!p->parent) {
    printf("root");
  } else if (!p->leftMostChild) {
    printf("leaf");
  } else {
    printf("internal node");
  }
}

void printChild(Node* p) {
  printf("[");

  if (p->leftMostChild) {
    Node* child = p->leftMostChild;
    printf("%d", child->id);

    while (child->rightSibling) {
      child = child->rightSibling;
      printf(", %d", child->id);
    }
  }

  printf("]");
}