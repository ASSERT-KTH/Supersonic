#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct Node {
  int key;
  Node *right, *left, *parent;
  
  // Add destructor to free memory
  ~Node(){
    delete left;
    delete right;
  }
};

Node *root, *NIL;

void insert(int k) {
  Node *y = NIL;
  Node *x = root;
  
  // Use new instead of malloc
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

void inorder(Node *root) {
  stack<Node *> nodeStack;
  Node *current = root;
  
  while (current != NIL || !nodeStack.empty()){
    while (current !=  NIL){
      nodeStack.push(current);
      current = current->left;
    }
    current = nodeStack.top();
    nodeStack.pop();
    printf(" %d", current->key);
    current = current->right;
  }
}

void preorder(Node *root) {
  if (root == NIL) return;
  stack<Node *> nodeStack;
  nodeStack.push(root);
  
  while (!nodeStack.empty()){
    struct Node *node = nodeStack.top();
    printf (" %d ", node->key);
    nodeStack.pop();
    
    if (node->right)
      nodeStack.push(node->right);
    if (node->left)
      nodeStack.push(node->left);
  }
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
  
  // Free memory
  delete root;
  
  return 0;
}