#include <iostream>
#include <string>
using namespace std;

struct Node {
  int key;
  Node *right = nullptr, *left = nullptr;
};

Node *root = nullptr;

void insert(int k) {
  Node *y = nullptr;
  Node *x = root;
  Node *z = new Node();
  z->key = k;

  while (x != nullptr) {
    y = x;
    if (z->key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  
  z->key = k;
  if (y == nullptr) {
    root = z;
  } else if (z->key < y->key) {
    y->left = z;
  } else {
    y->right = z;
  }
}

void inorder(Node *u) {
  if (u != nullptr) {
    inorder(u->left);
    cout << " " << u->key;
    inorder(u->right);
  }
}

void preorder(Node *u) {
  if (u != nullptr) {
    cout << " " << u->key;
    preorder(u->left);
    preorder(u->right);
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