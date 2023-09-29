#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

struct Node {
  int key;
  Node* right = nullptr;
  Node* left = nullptr;
  Node* parent = nullptr;
  Node(int key) : key(key) {};
};

Node* root = nullptr;

void insert(int k) {
  Node* y = nullptr;
  Node* x = root;
  Node* z = new Node(k);
  while (x != nullptr) {
    y = x;
    if (z->key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  z->parent = y;
  if (y == nullptr) {
    root = z;
  } else {
    if (z->key < y->key) {
      y->left = z;
    } else {
      y->right = z;
    }
  }
}

void inorder(Node* u) {
  if (u == nullptr) {
    return;
  }
  inorder(u->left);
  printf(" %d", u->key);
  inorder(u->right);
}

void preorder(Node* u) {
  if (u == nullptr) {
    return;
  }
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