#include <stdio.h>

#define MAX_NODES 1000

typedef struct node {
  int id;
  struct node* parent;
  struct node* leftMostChild;
  struct node* rightSibling;
  int depth;
} Node;

Node nodes[MAX_NODES];
int nodeCount = 0;

Node* make1node(int id) {
  Node* node = &nodes[nodeCount++];
  node->id = id;
  node->parent = NULL;
  node->leftMostChild = NULL;
  node->rightSibling = NULL;
  node->depth = 0;
  return node;
}

void printNode(Node* node) {
  printf("node %d: ", node->id);
  if (node->parent != NULL) {
    printf("parent = %d, ", node->parent->id);
  } else {
    printf("parent = -1, ");
  }
  printf("depth = %d, ", node->depth);
  
  if (node->parent == NULL) {
    printf("root");
  } else if (node->leftMostChild == NULL) {
    printf("leaf");
  } else {
    printf("internal node");
  }
  
  printf(", [");
  if (node->leftMostChild != NULL) {
    Node* child = node->leftMostChild;
    printf("%d", child->id);
    for (Node* sibling = child->rightSibling; sibling != NULL; sibling = sibling->rightSibling) {
      printf(", %d", sibling->id);
    }
  }
  printf("]\n");
}

int main(void) {
  int n;
  scanf("%d", &n);
  
  for (int i = 0; i < n; i++) {
    int id, k;
    scanf("%d %d", &id, &k);
    
    Node* node = make1node(id);
    Node* parent = (id == -1) ? NULL : &nodes[id];
    
    node->parent = parent;
    
    if (parent != NULL) {
      if (parent->leftMostChild == NULL) {
        parent->leftMostChild = node;
      } else {
        Node* sibling = parent->leftMostChild;
        while (sibling->rightSibling != NULL) {
          sibling = sibling->rightSibling;
        }
        sibling->rightSibling = node;
      }
    }
    
    if (parent != NULL) {
      node->depth = parent->depth + 1;
    }
  }
  
  for (int i = 0; i < nodeCount; i++) {
    printNode(&nodes[i]);
  }
  
  return 0;
}