#include <stdio.h>
#include <stdlib.h>

struct node {
  int id;
  struct node *parent;
  struct node *leftMostChild;
  struct node *rightSibling;
  int depth;
  int *children;
};

typedef struct node Node;

Node* make_node(int id) {
  Node* p = (Node*)malloc(sizeof(Node));
  p->id = id;
  p->parent = NULL;
  p->leftMostChild = NULL;
  p->rightSibling = NULL;
  p->depth = 0;
  p->children = NULL;
  return p;
}

Node* make_tree(int n) {
  int i, j;
  int id, k, c;
  Node* head = make_node(-1);
  Node* *nodes = (Node**)malloc(sizeof(Node*) * n);
  
  for (i = 0; i < n; i++) {
    nodes[i] = make_node(i);
  }
  
  for (i = 0; i < n; i++) {
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d %d", &id, &k);
    nodes[id]->children = (int*)malloc(sizeof(int) * k);
    
    for (j = 0; j < k; j++) {
      sscanf(buf, "%d", &c);
      if (j == 0) {
        nodes[id]->leftMostChild = nodes[c];
      } else {
        nodes[nodes[id]->children[j-1]]->rightSibling = nodes[c];
      }
      nodes[c]->parent = nodes[id];
      nodes[id]->children[j] = c;
    }
  }
  
  for (i = 0; i < n; i++) {
    Node* p = nodes[i];
    
    while (p->parent != NULL) {
      p->depth++;
      p = p->parent;
    }
  }
  
  return head;
}

void print_node(Node* p) {
  printf("node %d: parent = %d, depth = %d, ", p->id, (p->parent != NULL) ? p->parent->id : -1, p->depth);
  
  if (p->parent == NULL) {
    printf("root");
  } else if (p->leftMostChild == NULL) {
    printf("leaf");
  } else {
    printf("internal node");
  }
  
  printf(", [");
  
  if (p->leftMostChild != NULL) {
    Node* child = p->leftMostChild;
    printf("%d", child->id);
    
    while (child->rightSibling != NULL) {
      child = child->rightSibling;
      printf(", %d", child->id);
    }
  }
  
  printf("]\n");
}

int main(void) {
  int i;
  int n;
  Node* head;
  
  scanf("%d", &n);
  head = make_tree(n);
  
  for (i = 0; i < n; i++) {
    print_node(head->children[i]);
  }
  
  return 0;
}