#include <iostream>

struct Node {
  int key;
  Node *right, *left, *parent;
};

Node *root, *NIL;

void insert(int k) {
  Node *y = NIL;
  Node *x = root;
  Node *z = new Node;
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

void inorder(Node *u) {
  if (u == NIL)
    return;
  inorder(u->left);
  std::cout << " " << u->key;
  inorder(u->right);
}

void preorder(Node *u) {
  if (u == NIL)
    return;
  std::cout << " " << u->key;
  preorder(u->left);
  preorder(u->right);
}

int main() {
  int x;
  char com[10];

  std::cin >> x;

  for (int i = 0; i < x; i++) {
    std::cin >> com;
    if (com[0] == 'i') {
      std::cin >> x;
      insert(x);
    } else if (com[0] == 'p') {
      inorder(root);
      std::cout << std::endl;
      preorder(root);
      std::cout << std::endl;
    }
  }

  return 0;
}