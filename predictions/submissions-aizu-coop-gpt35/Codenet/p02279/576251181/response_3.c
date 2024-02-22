#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int id;
  int parent;
  int leftMostChild;
  int rightSibling;
  int depth;
} Node;

Node* init(Node* nodes, int id) {
  nodes[id].id = id;
  nodes[id].parent = -1;
  nodes[id].leftMostChild = -1;
  nodes[id].rightSibling = -1;
  nodes[id].depth = 0;
  return &nodes[id];
}

void printNode(Node* nodes, int id) {
  printf("node %d: ", nodes[id].id);
  if (nodes[id].parent != -1)
    printf("parent = %d, ", nodes[id].parent);
  else
    printf("parent = -1, ");
  printf("depth = %d, ", nodes[id].depth);
  
  if (nodes[id].parent == -1)
    printf("root");
  else if (nodes[id].leftMostChild == -1)
    printf("leaf");
  else
    printf("internal node");
  
  printf(", [");
  int child = nodes[id].leftMostChild;
  while (child != -1) {
    printf("%d", child);
    child = nodes[child].rightSibling;
    if (child != -1)
      printf(", ");
  }
  printf("]\n");
}

void calculateDepth(Node* nodes, int id) {
  if (nodes[id].parent != -1) {
    nodes[id].depth = nodes[nodes[id].parent].depth + 1;
  }
  
  int child = nodes[id].leftMostChild;
  while (child != -1) {
    calculateDepth(nodes, child);
    child = nodes[child].rightSibling;
  }
}

int main(void) {
  int n;
  scanf("%d", &n);
  
  Node* nodes = (Node*)malloc(sizeof(Node) * n);
  
  for (int i = 0; i < n; i++) {
    init(nodes, i);
  }
  
  for (int i = 0; i < n; i++) {
    int id, k, c1, c2;
    scanf("%d %d", &id, &k);
    
    for (int j = 0; j < k; j++) {
      scanf("%d", &c1);
      if (j == 0) {
        nodes[id].leftMostChild = c1;
      } else {
        nodes[c2].rightSibling = c1;
      }
      nodes[c1].parent = id;
      c2 = c1;
    }
  }
  
  calculateDepth(nodes, 0);
  
  for (int i = 0; i < n; i++) {
    printNode(nodes, i);
  }
  
  free(nodes);
  return 0;
}