#include <cstdio>

struct Node {
  int key;
  Node* right;
  Node* left;
  Node* parent;
};

void insert(Node*& root, int k) {
  Node* y = nullptr;
  Node* x = root;
  Node* z = new Node;
  z->key = k;
  z->left = nullptr;
  z->right = nullptr;
  while (x != nullptr) {
    y = x;
    if (z->key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  z->parent = y;
  if (y == nullptr) {
    root = z;
  } else {
    if (z->key < y->key) {
      y->left = z;
    } else {
      y->right = z;
    }
  }
}

void inorder(Node* u) {
  if (u == nullptr) return;
  inorder(u->left);
  printf(" %d", u->key);
  inorder(u->right);
}

void preorder(Node* u) {
  if (u == nullptr) return;
  printf(" %d", u->key);
  preorder(u->left);
  preorder(u->right);
}

int main() {
  Node* root = nullptr;
  int n, i, x;
  char com[10];
  std::scanf("%d", &n);
  for (i = 0; i < n; i++) {
    std::scanf("%s", com);
    if (com[0] == 'i') {
      std::scanf("%d", &x);
      insert(root, x);
    } else if (com[0] == 'p') {
      inorder(root);
      std::printf("\n");
      preorder(root);
      std::printf("\n");
    }
  }
  return 0;
}