#include <iostream>
#include <string>
#include <stack>
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
    root->parent = NIL;
  } else {
    if (z->key < y->key) {
      y->left = z;
    } else {
      y->right = z;
    }
  }
}

void inorder(Node *u) {
  stack<Node*> stk;
  while (u != NIL || !stk.empty()) {
    while (u != NIL) {
      stk.push(u);
      u = u->left;
    }
    u = stk.top();
    stk.pop();
    cout << " " << u->key;
    u = u->right;
  }
}

void preorder(Node *u) {
  if (u == NIL)
    return;
  stack<Node*> stk;
  stk.push(u);
  while (!stk.empty()) {
    Node* temp = stk.top();
    stk.pop();
    cout << " " << temp->key;
    if(temp->right)
      stk.push(temp->right);
    if(temp->left)
      stk.push(temp->left);
  }
}

void deleteTree(Node* node) {
  if (node == NIL)
    return;
  deleteTree(node->left);
  deleteTree(node->right);
  delete node;
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
  deleteTree(root);
  return 0;
}