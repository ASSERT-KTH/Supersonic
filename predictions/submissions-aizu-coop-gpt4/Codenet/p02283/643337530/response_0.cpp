#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct Node {
  int key;
  Node *right, *left, *parent;
};
Node *root, *NIL;

void insert(int k) {
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

void inorder(Node *u) {
  stack<Node*> s;
  while (u != NIL || !s.empty()) {
    while (u != NIL) {
      s.push(u);
      u = u->left;
    }
    u = s.top();
    s.pop();
    cout << " " << u->key;
    u = u->right;
  }
}

void preorder(Node *u) {
  stack<Node*> s;
  if (u != NIL)
    s.push(u);
  while (!s.empty()) {
    u = s.top();
    s.pop();
    cout << " " << u->key;
    if (u->right)
      s.push(u->right);
    if (u->left)
      s.push(u->left);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
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