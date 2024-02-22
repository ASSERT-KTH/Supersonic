#include <cstdio>
#include <iostream>
using namespace std;
struct Node {
  int key;
  Node *parent, *left, *right;
};

Node *root, *NIL;
Node *nodes;
int nodeCount;

void insert(int k) {
  Node *y = NIL;
  Node *x = root;
  Node *z = &nodes[nodeCount++];
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
    if (z->key < y->key)
      y->left = z;
    else
      y->right = z;
  }
}

bool find(int k) {
  Node *v = root;
  while (v != NIL) {
    if (k < v->key) {
      v = v->left;
    } else if (k > v->key) {
      v = v->right;
    } else {
      return true;
    }
  }
  return false;
}

void inorder(Node *u) {
  if (u == NIL)
    return;
  inorder(u->left);
  printf(" %d", u->key);
  inorder(u->right);
}

void preorder(Node *u) {
  if (u == NIL)
    return;
  printf(" %d", u->key);
  preorder(u->left);
  preorder(u->right);
}

int main() {
  int n, x;
  string com;
  cin >> n;

  // Allocate memory for nodes
  nodes = (Node*)malloc(n * sizeof(Node));
  nodeCount = 0;

  // Initialize NIL node
  NIL = &nodes[nodeCount++];
  NIL->key = 0;
  NIL->parent = NIL;
  NIL->left = NIL;
  NIL->right = NIL;

  root = NIL;

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

  // Free allocated memory
  free(nodes);

  return 0;
}