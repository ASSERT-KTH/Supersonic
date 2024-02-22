#include <iostream>
using namespace std;

struct Node {
  int key;
  Node *parent, *left, *right;
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
    x = (k < x->key) ? x->left : x->right;
  }
  
  z->parent = y;
  
  if (y != NIL) {
    if (k < y->key)
      y->left = z;
    else
      y->right = z;
  } else {
    root = z;
  }
}

bool find(int k) {
  Node *v = root;
  while (v != NIL) {
    if (k == v->key)
      return true;
    v = (k < v->key) ? v->left : v->right;
  }
  return false;
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
  for (int i = 0; i < n; i++) {
    cin >> com;
    if (com == "insert") {
      cin >> x;
      insert(x);
    } else if (com == "print") {
      inorder(root);
      cout << endl;
      preorder(root);
      cout << endl;
    } else if (com == "find") {
      cin >> x;
      if (find(x))
        cout << "yes" << endl;
      else
        cout << "no" << endl;
    }
  }
  return 0;
}