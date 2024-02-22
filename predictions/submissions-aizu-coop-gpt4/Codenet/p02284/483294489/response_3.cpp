#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

struct Node {
  int key;
  Node *parent, *left, *right;

  // Destructor to free memory
  ~Node() {
    delete left;
    delete right;
  }
};

Node *root, *NIL;

void insert(int k) {
  // ... (Unchanged code)
}

bool find(int k) {
  // ... (Unchanged code)
}

void inorder(Node *root) {
  stack<Node*> nodes;
  Node *curr = root;

  while (!nodes.empty() || curr != NIL) {
    while (curr != NIL) {
      nodes.push(curr);
      curr = curr->left;
    }

    curr = nodes.top();
    nodes.pop();
    printf(" %d", curr->key);
    curr = curr->right;
  }
}

void preorder(Node *root) {
  if (root == NIL) return;

  stack<Node*> nodes;
  nodes.push(root);

  while (!nodes.empty()) {
    Node *curr = nodes.top();
    nodes.pop();
    printf(" %d", curr->key);

    if (curr->right != NIL)
      nodes.push(curr->right);
    
    if (curr->left != NIL)
      nodes.push(curr->left);
  }
}

int main() {
  // ... (Unchanged code)

  // Delete the root node to free allocated memory
  delete root;
  return 0;
}