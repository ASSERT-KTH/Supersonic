#include <iostream>
#include <memory>
#include <string>
using namespace std;

struct Node {
  int key;
  shared_ptr<Node> parent, left, right;
  Node(int key) : key(key), parent(nullptr), left(nullptr), right(nullptr) {}
};

shared_ptr<Node> root;

void insert(int k) {
  shared_ptr<Node> y = nullptr;
  shared_ptr<Node> x = root;
  shared_ptr<Node> z = make_shared<Node>(k);
  while (x != nullptr) {
    y = x;
    if (z->key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  z->parent = y;
  if (y == nullptr) {
    root = z;
  } else if (z->key < y->key) {
    y->left = z;
  } else {
    y->right = z;
  }
}

bool find(int k) {
  shared_ptr<Node> v = root;
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

void inorder(shared_ptr<Node> u) {
  if (u == nullptr)
    return;
  inorder(u->left);
  cout << " " << u->key;
  inorder(u->right);
}

void preorder(shared_ptr<Node> u) {
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
      insert(x);
    } else if (com == "print") {
      inorder(root);
      cout << endl;
      preorder(root);
      cout << endl;
    } else if (com == "find") {
      cin >> x;
      cout << (find(x) ? "yes" : "no") << endl;
    }
  }
  return 0;
}