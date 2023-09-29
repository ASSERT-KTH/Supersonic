#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int id;
  struct node *parent;
  struct node *leftMostChild;
  struct node *rightSibling;
} node_t;

node_t* make1node(void);
void printNode(node_t*);
int getDepth(node_t*);
void printType(node_t*);
void printChild(node_t*);
node_t* init(int);

node_t* head;

int main(void) {
  int i, j;
  int n;
  int id;
  int k;
  int c1, c2;
  node_t *p1, *p2;
  node_t **arr;
  
  head = init(-1);
  scanf("%d", &n);
  arr = (node_t **)malloc(sizeof(node_t*) * n);
  
  for (i = 0; i < n; i++)
    arr[i] = init(i);
  
  for (i = 0; i < n; i++) {
    scanf("%d", &id);
    scanf("%d", &k);
    
    if(k > 0){
        arr[id]->leftMostChild = arr[c1 = getchar() - '0'];
        for (j = 1; j < k; j++) {
            arr[c1]->rightSibling = arr[c2 = getchar() - '0'];
            arr[c2]->parent = arr[id];
            c1 = c2;
        }
        arr[c1]->rightSibling = NULL;
        arr[c1]->parent = arr[id];
    }
  }
  
  for (i = 0; i < n; i++)
    printNode(arr[i]);
  
  free(arr);
  return 0;
}

node_t* init(int id) {
  node_t *p = make1node();
  p->id = id;
  p->parent = NULL;
  p->leftMostChild = NULL;
  p->rightSibling = NULL;
  return p;
}

void printNode(node_t *p) {
  printf("node %d: ", p->id);
  
  if (p->parent != NULL)
    printf("parent = %d, ", p->parent->id);
  else
    printf("parent = -1, ");
  
  printf("depth = %d, ", getDepth(p));
  printType(p);
  printf(", ");
  printChild(p);
  printf("\n");
}

node_t* make1node(void) {
  node_t *p = (node_t*)malloc(sizeof(node_t));
  return p;
}

int getDepth(node_t *p) {
  int depth = 0;
  while(p->parent != NULL){
    depth++;
    p = p->parent;
  }
  return depth;
}

void printType(node_t *p) {
  if (p->parent == NULL)
    printf("root");
  else if (p->leftMostChild == NULL)
    printf("leaf");
  else
    printf("internal node");
}

void printChild(node_t *p) {
  printf("[");
  if (p->leftMostChild != NULL) {
    p = p->leftMostChild;
    printf("%d", p->id);
    for (; p->rightSibling != NULL; p = p->rightSibling)
      printf(", %d", p->rightSibling->id);
  }
  printf("]");
}
