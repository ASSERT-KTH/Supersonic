#include <iostream>
using namespace std;

struct Node {
  int key;
  Node* parent;
  Node* left;
  Node* right;
};

Node* root = nullptr;
Node* preAllocatedNode = nullptr;

void insert(int k) {
  Node* y = nullptr;
  Node* x = root;
  Node* z;
  
  if (preAllocatedNode != nullptr) {
    z = preAllocatedNode;
    preAllocatedNode = nullptr;
  } else {
    z = new Node;
  }
  
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

bool find(int k) {
  Node* v = root;
  
  while (v != nullptr) {
    if (k == v->key) {
      return true;
    }
    
    if (k < v->key) {
      v = v->left;
    } else {
      v = v->right;
    }
  }
  
  return false;
}

void inorder(Node* u) {
  if (u == nullptr) {
    return;
  }
  
  inorder(u->left);
  cout << " " << u->key;
  inorder(u->right);
}

void preorder(Node* u) {
  if (u == nullptr) {
    return;
  }
  
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
      if (find(x)) {
        cout << "yes" << endl;
      } else {
        cout << "no" << endl;
      }
    }
  }
  
  // Deallocate pre-allocated node if exists
  delete preAllocatedNode;
  
  return 0;
}