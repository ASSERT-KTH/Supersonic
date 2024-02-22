#include <iostream>
#include <string>
using namespace std;
struct Node {
  int key;
  Node *right, *left, *parent;
};
Node *root = nullptr, *NIL = nullptr;
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
  cout << " " << u->key;
  inorder(u->right);
}
void preorder(Node *u) {
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
  for (int i = 0; i < n; ++i) {
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