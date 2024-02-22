#include <cstdio>
#include <iostream>
using namespace std;
struct Node {
  int key;
  Node *parent, *left, *right;
  ~Node() {
    delete left;
    delete right;
  }
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
    if (z->key < y->key)
      y->left = z;
    else
      y->right = z;
  }
}
bool find(int k) {
  Node *v = root;
  while (v != NIL) {
    if (k == v->key)
      return true;
    if (k < v->key) {
      v = v->left;
    } else {
      v = v->right;
    }
  }
  return false;
}
void inorder(Node *u) {
  if (u == NIL)
    return;
  inorder(u->left);
  printf(" %d", u->key);
  inorder(u->right);
}
void preorder(Node *u) {
  if (u == NIL)
    return;
  printf(" %d", u->key);
  preorder(u->left);
  preorder(u->right);
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
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
      cout << '\n';
      preorder(root);
      cout << '\n';
    } else if (com == "find") {
      cin >> x;
      if (find(x))
        cout << "yes" << '\n';
      else
        cout << "no" << '\n';
    }
  }
  delete root;
  return 0;
}