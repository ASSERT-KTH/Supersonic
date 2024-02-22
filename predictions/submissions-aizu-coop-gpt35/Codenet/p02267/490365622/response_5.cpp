#include <stdio.h>

// Node structure for binary search tree
typedef struct Node {
  int value;
  struct Node* left;
  struct Node* right;
} Node;

// Function to insert a value into the binary search tree
Node* insert(Node* root, int value) {
  if (root == NULL) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
  }

  if (value < root->value) {
    root->left = insert(root->left, value);
  } else if (value > root->value) {
    root->right = insert(root->right, value);
  }

  return root;
}

// Function to search for a value in the binary search tree
int search(Node* root, int value) {
  if (root == NULL) {
    return 0;
  }

  if (value == root->value) {
    return 1;
  } else if (value < root->value) {
    return search(root->left, value);
  } else {
    return search(root->right, value);
  }
}

int main() {
  int n, q, i, cnt = 0;
  Node* root = NULL;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    root = insert(root, num);
  }

  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    int num;
    scanf("%d", &num);
    cnt += search(root, num);
  }

  printf("%d\n", cnt);

  return 0;
}