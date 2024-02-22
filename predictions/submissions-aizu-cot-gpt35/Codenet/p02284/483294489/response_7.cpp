#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
  int key;
  Node* parent;
  Node* left;
  Node* right;
};

Node* root = nullptr;
unordered_set<int> keys;

void insert(int k) {
  if (keys.find(k) != keys.end()) {
    return;
  }
  
  Node* y = nullptr;
  Node* x = root;
  Node* z = new Node;
  
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
  
  keys.insert(k);
}

bool find(int k) {
  return keys.find(k) != keys.end();
}

void inorder(Node& u) {
  if (u.left != nullptr) {
    inorder(*u.left);
  }
  
  cout << " " << u.key;
  
  if (u.right != nullptr) {
    inorder(*u.right);
  }
}

void preorder(Node& u) {
  cout << " " << u.key;
  
  if (u.left != nullptr) {
    preorder(*u.left);
  }
  
  if (u.right != nullptr) {
    preorder(*u.right);
  }
}

int main() {
  int n, x;
  string com;
  cin >> n;
  
  for (int i = 0; i < n; i++) {
    cin >> com;
    
    switch (com[0]) {
      case 'i':
        cin >> x;
        insert(x);
        break;
      
      case 'p':
        inorder(*root);
        cout << endl;
        preorder(*root);
        cout << endl;
        break;
      
      case 'f':
        cin >> x;
        if (find(x)) {
          cout << "yes" << endl;
        } else {
          cout << "no" << endl;
        }
        break;
    }
  }
  
  return 0;
}