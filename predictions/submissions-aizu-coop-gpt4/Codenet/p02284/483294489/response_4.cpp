#include <cstdio>
#include <iostream>
#include <stack>
#define MAX 100000
using namespace std;
struct Node {
  int key;
  Node *parent, *left, *right;
};
Node *root, *NIL;
Node nodePool[MAX];
int poolCounter = 0;

Node* getNode() {
  return &nodePool[poolCounter++];
}

void insert(int k) {
  Node *y = NIL;
  Node *x = root;
  Node *z = getNode();
  z->key = k;
  z->left = NIL;
  z->right = NIL;
  while (x != NIL) {
    y = x;
    x = (z->key < x->key) ? x->left : x->right;
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
    v = (k < v->key) ? v->left : v->right;
  }
  return false;
}

void inorder(Node *u) {
  stack<Node*> s;
  Node *curr = u;

  while (curr != NIL || s.empty() == false) {
    while (curr !=  NIL) {
      s.push(curr);
      curr = curr->left;
    }
    curr = s.top();
    s.pop();
    printf(" %d", curr->key);
    curr = curr->right;
  }
}

void preorder(Node *u) {
  if (u == NIL)
    return;
  stack<Node*> s;
  s.push(u);

  while (!s.empty()) {
    Node* node = s.top();
    printf(" %d", node->key);
    s.pop();

    if (node->right)
      s.push(node->right);
    if (node->left)
      s.push(node->left);
  }
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