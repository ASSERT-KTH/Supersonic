#include <iostream>
#include <string>
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
  if (u == nullptr)
    return;
  
  Node *current = u;
  Node *predecessor;
  
  while (current != nullptr) {
    if (current->left == nullptr) {
      cout << " " << current->key;
      current = current->right;
    } else {
      predecessor = current->left;
      
      while (predecessor->right != nullptr && predecessor->right != current) {
        predecessor = predecessor->right;
      }
      
      if (predecessor->right == nullptr) {
        predecessor->right = current;
        current = current->left;
      } else {
        predecessor->right = nullptr;
        cout << " " << current->key;
        current = current->right;
      }
    }
  }
}

void preorder(Node *u) {
  if (u == nullptr)
    return;
  
  Node *current = u;
  Node *predecessor;
  
  while (current != nullptr) {
    if (current->left == nullptr) {
      cout << " " << current->key;
      current = current->right;
    } else {
      predecessor = current->left;
      
      while (predecessor->right != nullptr && predecessor->right != current) {
        predecessor = predecessor->right;
      }
      
      if (predecessor->right == nullptr) {
        predecessor->right = current;
        cout << " " << current->key;
        current = current->left;
      } else {
        predecessor->right = nullptr;
        current = current->right;
      }
    }
  }
}

int main() {
  int n, i, x;
  string com;
  cin >> n;
  
  for (i = 0; i < n; i++) {
    cin >> com;
    
    if (com == "insert") {
      cin >> x;
      insert(x);
    } else if (com == "print") {
      inorder(root);
      cout << endl;
      preorder(root);
      cout << endl;
    }
  }
  
  return 0;
}