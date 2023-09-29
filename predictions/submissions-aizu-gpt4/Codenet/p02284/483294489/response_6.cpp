#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;
struct Node {
  int key;
  Node *parent, *left, *right;
};
Node *root, *NIL;
unordered_map<int, Node*> m;
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
  m[k] = z;
}
bool find(int k) {
  return m.find(k) != m.end();
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
  ios::sync_with_stdio(false);
  cin.tie(0);
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
  return 0;
}