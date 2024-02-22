#include <cstdio>
#include <iostream>
using namespace std;

struct Node {
  int key;
  Node *right, *left, *parent;
};

Node *root = nullptr;

void insert(int k) {
  Node *y = nullptr;
  Node *x = root;
  Node *z = new Node;
  z->key = k;
  z->left = nullptr;
  z->right = nullptr;
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

void inorder(Node *u) {
  Node *current = u;
  Node *pre;
  while (current != nullptr) {
    if (current->left == nullptr) {
      cout << " " << current->key;
      current = current->right;
    } else {
      pre = current->left;
      while (pre->right != nullptr && pre->right != current) {
        pre = pre->right;
      }
      if (pre->right == nullptr) {
        pre->right = current;
        current = current->left;
      } else {
        pre->right = nullptr;
        cout << " " << current->key;
        current = current->right;
      }
    }
  }
}

void preorder(Node *u) {
  Node *current = u;
  while (current != nullptr) {
    if (current->left == nullptr) {
      cout << " " << current->key;
      current = current->right;
    } else {
      Node *pre = current->left;
      while (pre->right != nullptr && pre->right != current) {
        pre = pre->right;
      }
      if (pre->right == nullptr) {
        pre->right = current;
        cout << " " << current->key;
        current = current->left;
      } else {
        pre->right = nullptr;
        current = current->right;
      }
    }
  }
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