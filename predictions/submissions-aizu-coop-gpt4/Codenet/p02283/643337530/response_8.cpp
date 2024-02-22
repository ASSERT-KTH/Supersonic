#include <cstdio>
#include <cstdlib>
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
  Node *z;
  z = (Node *)malloc(sizeof(Node));
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
  stack<Node*> st;
  Node *curr = root;

  while (curr != NIL || !st.empty()) {
    while (curr !=  NIL) {
      st.push(curr);
      curr = curr->left;
    }
    curr = st.top();
    st.pop();

    printf(" %d", curr->key);

    curr = curr->right;
  }
}

void preorder(Node *root) {
  if (root == NIL) {
    return;
  }

  stack<Node*> st;
  st.push(root);

  while (!st.empty()) {
    Node *node = st.top();
    printf(" %d", node->key);
    st.pop();

    if (node->right != NIL) {
      st.push(node->right);
    }
    if (node->left != NIL) {
      st.push(node->left);
    }
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
  return 0;
}