#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
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
    x = (z->key < x->key) ? x->left : x->right;
  }
  z->parent = y;
  if (y == NIL)
    root = z;
  else
    (z->key < y->key) ? y->left = z : y->right = z;
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
  int n, i, x;
  string com;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    cin >> com;
    if (com == "insert") {
      scanf("%d", &x);
      insert(x);
    } else if (com == "print") {
      inorder(root);
      printf("\n");
      preorder(root);
      printf("\n");
    }
  }
  return 0;
}
