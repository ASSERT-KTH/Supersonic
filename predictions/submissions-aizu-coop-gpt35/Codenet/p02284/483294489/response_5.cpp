#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

const int MAX_NODES = 1000000; // Maximum number of nodes in the BST

struct Node {
  int key;
  Node *parent, *left, *right;
};

Node nodes[MAX_NODES]; // Memory pool for nodes
int nextNodeIndex = 0; // Index of the next available node slot in the memory pool

Node* createNode(int k, Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr) {
  Node* node = &nodes[nextNodeIndex++];
  node->key = k;
  node->parent = parent;
  node->left = left;
  node->right = right;
  return node;
}

Node *root, *NIL;

void insert(int k) {
  Node *y = NIL;
  Node *x = root;
  Node *z = createNode(k);
  
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
    if (z->key < y->key)
      y->left = z;
    else
      y->right = z;
  }
}

bool find(int k) {
  Node *v = root;
  
  while (v != NIL) {
    if (k == v->key)
      return true;
    if (k < v->key) {
      v = v->left;
    } else {
      v = v->right;
    }
  }
  
  return false;
}

void inorder(Node *u) {
  stack<Node*> stk;
  Node* curr = u;
  
  while (curr != NIL || !stk.empty()) {
    while (curr != NIL) {
      stk.push(curr);
      curr = curr->left;
    }
    
    curr = stk.top();
    stk.pop();
    
    printf(" %d", curr->key);
    
    curr = curr->right;
  }
}

void preorder(Node *u) {
  stack<Node*> stk;
  stk.push(u);
  
  while (!stk.empty()) {
    Node* curr = stk.top();
    stk.pop();
    
    printf(" %d", curr->key);
    
    if (curr->right != NIL)
      stk.push(curr->right);
    if (curr->left != NIL)
      stk.push(curr->left);
  }
}

int main() {
  int n, x;
  string com;
  scanf("%d", &n);
  
  for (int i = 0; i < n; i++) {
    cin >> com;
    
    if (com == "insert") {
      scanf("%d", &x);
      insert(x);
    } else if (com == "print") {
      inorder(root);
      printf("\n");
      preorder(root);
      printf("\n");
    } else if (com == "find") {
      scanf("%d", &x);
      
      if (find(x))
        printf("yes\n");
      else
        printf("no\n");
    }
  }
  
  return 0;
}