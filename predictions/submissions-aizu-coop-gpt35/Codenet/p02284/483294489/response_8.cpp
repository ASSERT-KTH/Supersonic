#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

struct Node {
  int key;
  int size;
  Node *parent, *left, *right;
};

const int MAX_NODES = 100000; // Maximum number of nodes
Node nodes[MAX_NODES]; // Pre-allocated array of nodes
int nodeIdx = 0; // Current index in the nodes array

Node *root, *NIL;

// Custom memory pool for allocating nodes
Node* allocateNode(int k) {
  Node* newNode = &nodes[nodeIdx++];
  newNode->key = k;
  newNode->left = NIL;
  newNode->right = NIL;
  newNode->size = 1;
  return newNode;
}

// Insert a node with key k into the binary search tree
void insert(int k) {
  Node *y = NIL;
  Node *x = root;
  Node *z = allocateNode(k);
  
  while (x != NIL) {
    y = x;
    if (z->key < x->key) {
      x->size++; // Increment the size of the left subtree
      x = x->left;
    } else {
      x->size++; // Increment the size of the right subtree
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

// Find a node with key k in the binary search tree
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

// Inorder tree traversal (iterative)
void inorder(Node *u) {
  vector<Node*> stack;
  Node* current = u;
  while (current != NIL || !stack.empty()) {
    while (current != NIL) {
      stack.push_back(current);
      current = current->left;
    }
    current = stack.back();
    stack.pop_back();
    printf(" %d", current->key);
    current = current->right;
  }
}

// Preorder tree traversal (iterative)
void preorder(Node *u) {
  vector<Node*> stack;
  stack.push_back(u);
  while (!stack.empty()) {
    Node* current = stack.back();
    stack.pop_back();
    printf(" %d", current->key);
    if (current->right != NIL) {
      stack.push_back(current->right);
    }
    if (current->left != NIL) {
      stack.push_back(current->left);
    }
  }
}

int main() {
  int n, x;
  string com;
  cin >> n;
  
  // Initialize NIL node
  NIL = allocateNode(0);
  NIL->parent = NIL->left = NIL->right = NIL;
  
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
      if (find(x))
        cout << "yes" << endl;
      else
        cout << "no" << endl;
    }
  }
  return 0;
}