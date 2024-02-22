#include <stdio.h>
#include <stdlib.h>

struct node {
  int id;
  struct node *parent;
  struct node *leftMostChild;
  struct node *rightSibling;
};

typedef struct node node;

node* make1node(void);
void printNode(node*);
int getDepth(node*);
void printType(node*);
void printChild(node*);
node* init(int);

node* head;

int main(void) {
  int i, j;
  int n;
  int id;
  int k;
  int c1, c2;
  node** arr;

  head = init(-1);

  scanf("%d", &n);

  arr = (node**)calloc(n, sizeof(node*));

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

  free(arr);

  return 0;
}

node* init(int id) {
  node* p = make1node();
  p->id = id;
  return p;
}

void printNode(node* p) {
  printf("node %d: parent = %d, depth = %d, ", p->id, (p->parent != NULL) ? p->parent->id : -1, getDepth(p));
  printType(p);
  printf(", ");
  printChild(p);
  printf("\n");
}

node* make1node(void) {
  node* p = (node*)malloc(sizeof(node));
  return p;
}

int getDepth(node* p) {
  int depth = 0;

  while (p->parent != NULL) {
    depth++;
    p = p->parent;
  }

  return depth;
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
    p = p->leftMostChild;
    printf("%d", p->id);

    for (; p->rightSibling != NULL; p = p->rightSibling)
      printf(", %d", p->rightSibling->id);
  }

  printf("]");
}