#include <cstdio>

struct Node {
  int key;
  Node *right, *left, *parent;
};

Node *root = nullptr;

void insert(int k) {
  Node *y = nullptr;
  Node *x = root;
  Node *z = new Node;
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

void inorder(Node *u) {
  if (u == nullptr)
    return;
  inorder(u->left);
  std::cout << " " << u->key;
  inorder(u->right);
}

void preorder(Node *u) {
  if (u == nullptr)
    return;
  std::cout << " " << u->key;
  preorder(u->left);
  preorder(u->right);
}

int main() {
  int n, i, x;
  std::string com;
  std::scanf("%d", &n);
  
  for (i = 0; i < n; i++) {
    std::cin >> com;
    if (com == "insert") {
      std::scanf("%d", &x);
      insert(x);
    } else if (com == "print") {
      inorder(root);
      std::cout << "\n";
      preorder(root);
      std::cout << "\n";
    }
  }
  
  return 0;
}