#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct Node {
  int key;
  shared_ptr<Node> right, left, parent;
};

shared_ptr<Node> root, NIL;

void insert(int k) {
  shared_ptr<Node> y = NIL;
  shared_ptr<Node> x = root;
  shared_ptr<Node> z = make_shared<Node>();
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

void inorder(const shared_ptr<Node>& u) {
  if (u == NIL)
    return;
  inorder(u->left);
  cout << " " << u->key;
  inorder(u->right);
}

void preorder(const shared_ptr<Node>& u) {
  if (u == NIL)
    return;
  cout << " " << u->key;
  preorder(u->left);
  preorder(u->right);
}

int main() {
  int n, x;
  string com;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> com;
    if (com == "insert") {
      cin >> x;
      insert(x);
    } else if (com == "print") {
      inorder(root);
      cout << "\n";
      preorder(root);
      cout << "\n";
    }
  }
  return 0;
}