#include <cstdio>
#include <iostream>
using namespace std;

const int MAX_NODES = 100000; // Maximum number of nodes in the BST

struct Node {
  int key;
  Node *parent, *left, *right;
};

Node nodes[MAX_NODES]; // Static memory allocation for nodes
int nodeCount = 0; // Counter for tracking the number of nodes

// Helper function to initialize a new node
Node* initializeNode(int k, Node *parent) {
  Node *node = &nodes[nodeCount++];
  node->key = k;
  node->parent = parent;
  node->left = nullptr;
  node->right = nullptr;
  return node;
}

void insert(int k) {
  // Special case for the root node
  if (nodeCount == 0) {
    root = initializeNode(k, nullptr);
    return;
  }

  Node *y = nullptr;
  Node *x = root;
  Node *z;

  // Find the appropriate position to insert the new key
  while (x != nullptr) {
    y = x;
    if (z->key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }

  // Create and initialize the new node
  z = initializeNode(k, y);

  // Insert the new node as a child of y
  if (z->key < y->key) {
    y->left = z;
  } else {
    y->right = z;
  }
}

bool find(int k) {
  Node *v = root;

  // Traverse the tree to find the key
  while (v != nullptr) {
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
  if (u == nullptr)
    return;
  inorder(u->left);
  printf(" %d", u->key);
  inorder(u->right);
}

void preorder(Node *u) {
  if (u == nullptr)
    return;
  printf(" %d", u->key);
  preorder(u->left);
  preorder(u->right);
}

int main() {
  int n, x;
  string com;
  cin >> n;

  // Optimization: Use scanf for faster input
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