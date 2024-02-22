#include <iostream>
using namespace std;

struct Node {
  int key;
  Node *parent, *left, *right;
};

Node *root = nullptr;

void insert(Node*& u, int k, Node* parent = nullptr) {
  if (u == nullptr) {
    u = new Node;
    u->key = k;
    u->left = nullptr;
    u->right = nullptr;
    u->parent = parent;
  } else if (k < u->key) {
    insert(u->left, k, u);
  } else {
    insert(u->right, k, u);
  }
}

bool find(Node* u, int k) {
  if (u == nullptr)
    return false;
  if (k == u->key)
    return true;
  if (k < u->key)
    return find(u->left, k);
  return find(u->right, k);
}

void inorder(Node* u) {
  if (u == nullptr)
    return;
  inorder(u->left);
  cout << " " << u->key;
  inorder(u->right);
}

void preorder(Node* u) {
  if (u == nullptr)
    return;
  cout << " " << u->key;
  preorder(u->left);
  preorder(u->right);
}

int main() {
  int n, x;
  string com;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> com;
    if (com == "insert") {
      cin >> x;
      insert(root, x);
    } else if (com == "print") {
      inorder(root);
      cout << endl;
      preorder(root);
      cout << endl;
    } else if (com == "find") {
      cin >> x;
      if (find(root, x))
        cout << "yes" << endl;
      else
        cout << "no" << endl;
    }
  }
  return 0;
}