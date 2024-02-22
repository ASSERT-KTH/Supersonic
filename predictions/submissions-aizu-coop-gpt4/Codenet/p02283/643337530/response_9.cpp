#include <iostream>
#include <vector>
#include <stack>
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
    if (z->key < y->key) {
      y->left = z;
    } else {
      y->right = z;
    }
  }
}

void inorder(Node* root) {
  stack<Node*> stk;
  Node* curr = root;
  
  while (curr != NIL || !stk.empty()) {
    while (curr !=  NIL) {
      stk.push(curr);
      curr = curr->left;
    }
    curr = stk.top();
    stk.pop();
    cout << " " << curr->key;
    curr = curr->right;
  }
  cout << "\n";
}

void preorder(Node* root) {
  stack<Node*> stk;
  if (root != NIL) {
    stk.push(root);
  }
  
  while (!stk.empty()) {
    Node* curr = stk.top();
    cout << " " << curr->key;
    stk.pop();
  
    if (curr->right != NIL) {
      stk.push(curr->right);
    }
    if (curr->left != NIL) {
      stk.push(curr->left);
    }
  }
  cout << "\n";
}

int main() {
  std::ios_base::sync_with_stdio(false);
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
      preorder(root);
    }
  }
  return 0;
}