#include <iostream>
#include <string>
using namespace std;

struct Node {
  int key;
  Node *right, *left, *parent;
};

Node* insert(Node* root, Node* NIL, int k) {
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
  return root;
}

inline void inorder(Node *u, Node* NIL) {
  if (u == NIL)
    return;
  inorder(u->left, NIL);
  cout << " " << u->key;
  inorder(u->right, NIL);
}

inline void preorder(Node *u, Node* NIL) {
  if (u == NIL)
    return;
  cout << " " << u->key;
  preorder(u->left, NIL);
  preorder(u->right, NIL);
}

int main() {
  int n, i, x;
  string com;
  Node *root = nullptr, *NIL = nullptr;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> com;
    if (com == "insert") {
      cin >> x;
      root = insert(root, NIL, x);
    } else if (com == "print") {
      inorder(root, NIL);
      cout << "\n";
      preorder(root, NIL);
      cout << "\n";
    }
  }
  return 0;
}