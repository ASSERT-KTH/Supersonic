#include <iostream>
#include <stack>
using namespace std;

struct Node {
  int key;
  Node* parent;
  Node* left;
  Node* right;
};

const int MAX_NODES = 100000;
Node nodes[MAX_NODES];
int nodeIndex = 0;

Node* root = nullptr;
Node* NIL = nullptr;

void insert(int k) {
  Node* y = NIL;
  Node* x = root;
  Node* z = &nodes[nodeIndex++];
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
  Node* v = root;
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

void inorder(Node* u) {
  stack<Node*> st;
  Node* curr = u;
  while (curr != NIL || !st.empty()) {
    while (curr != NIL) {
      st.push(curr);
      curr = curr->left;
    }
    curr = st.top();
    st.pop();
    cout << " " << curr->key;
    curr = curr->right;
  }
}

void preorder(Node* u) {
  stack<Node*> st;
  if (u != NIL)
    st.push(u);
  while (!st.empty()) {
    Node* curr = st.top();
    st.pop();
    cout << " " << curr->key;
    if (curr->right != NIL)
      st.push(curr->right);
    if (curr->left != NIL)
      st.push(curr->left);
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