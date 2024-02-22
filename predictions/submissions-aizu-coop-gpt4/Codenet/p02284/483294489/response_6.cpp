#include <cstdio>
#include <iostream>
using namespace std;
enum Command {
  INSERT = 0,
  PRINT = 1,
  FIND = 2
};
struct Node {
  int key;
  Node *parent, *left, *right;
};
Node *root = NULL;
void insert(int k) {
  Node *y = NULL;
  Node *x = root;
  Node *z;
  z = new Node;
  z->key = k;
  z->left = NULL;
  z->right = NULL;
  while (x != NULL) {
    y = x;
    if (z->key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  z->parent = y;
  if (y == NULL) {
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
  while (v != NULL) {
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
  if (u == NULL)
    return;
  inorder(u->left);
  printf(" %d", u->key);
  inorder(u->right);
}
void preorder(Node *u) {
  if (u == NULL)
    return;
  printf(" %d", u->key);
  preorder(u->left);
  preorder(u->right);
}
int main() {
  int n, x, command;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &command);
    switch(command) {
      case INSERT:
        scanf("%d", &x);
        insert(x);
        break;
      case PRINT:
        inorder(root);
        printf("\n");
        preorder(root);
        printf("\n");
        break;
      case FIND:
        scanf("%d", &x);
        if (find(x))
          printf("yes\n");
        else
          printf("no\n");
        break;
    }
  }
  return 0;
}