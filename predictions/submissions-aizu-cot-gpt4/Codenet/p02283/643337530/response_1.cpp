#include <iostream>
#include <string>

struct Node {
  int key;
  Node *right, *left, *parent;
};

void insert(Node *&root, Node *&NIL, int k) {
  Node *y = NIL;
  Node *x = root;
  Node *z;
  z = new Node;
  z->key = k;
  z->left = NIL;
  z->right = NIL;
  while (x != NIL) {
    y = x;
    if (z->key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  z->parent = y;
  if (y == NIL) {
    root = z;
  } else {
    if (z->key < y->key) {
      y->left = z;
    } else {
      y->right = z;
    }
  }
}

void inorder(Node *u, Node *&NIL) {
  if (u == NIL)
    return;
  inorder(u->left, NIL);
  std::cout << " " << u->key;
  inorder(u->right, NIL);
}

void preorder(Node *u, Node *&NIL) {
  if (u == NIL)
    return;
  std::cout << " " << u->key;
  preorder(u->left, NIL);
  preorder(u->right, NIL);
}

int main() {
  Node *root = nullptr;
  Node *NIL = nullptr;
  int n, i, x;
  std::string com;
  std::cin >> n;
  for (i = 0; i < n; i++) {
    std::cin >> com;
    if (com == "insert") {
      std::cin >> x;
      insert(root, NIL, x);
    } else if (com == "print") {
      inorder(root, NIL);
      std::cout << "\n";
      preorder(root, NIL);
      std::cout << "\n";
    }
  }
  return 0;
}