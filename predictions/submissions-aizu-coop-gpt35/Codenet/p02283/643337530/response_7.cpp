#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Node {
  int key;
  Node *right, *left;
};

Node *root, *NIL;

void insert(int k) {
  Node *current = root;
  Node *parent = NIL;
  Node *newNode = new Node;
  newNode->key = k;
  newNode->left = NIL;
  newNode->right = NIL;
  while (current != NIL) {
    parent = current;
    if (newNode->key < current->key) {
      current = current->left;
    } else {
      current = current->right;
    }
  }
  newNode->parent = parent;
  if (parent == NIL) {
    root = newNode;
  } else {
    if (newNode->key < parent->key) {
      parent->left = newNode;
    } else {
      parent->right = newNode;
    }
  }
}

void inorder(Node *root) {
  if (root == NIL) {
    return;
  }

  stack<Node*> st;
  Node* current = root;

  while (!st.empty() || current != NIL) {
    while (current != NIL) {
      st.push(current);
      current = current->left;
    }

    current = st.top();
    st.pop();
    printf(" %d", current->key);

    current = current->right;
  }
}

void preorder(Node *root) {
  if (root == NIL) {
    return;
  }

  stack<Node*> st;
  st.push(root);

  while (!st.empty()) {
    Node* current = st.top();
    st.pop();
    printf(" %d", current->key);

    if (current->right != NIL) {
      st.push(current->right);
    }

    if (current->left != NIL) {
      st.push(current->left);
    }
  }
}

int main() {
  int n, i, x;
  string com;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    cin >> com;
    switch (com[0]) {
      case 'i':
        scanf("%d", &x);
        insert(x);
        break;
      case 'p':
        inorder(root);
        printf("\n");
        preorder(root);
        printf("\n");
        break;
    }
  }
  return 0;
}