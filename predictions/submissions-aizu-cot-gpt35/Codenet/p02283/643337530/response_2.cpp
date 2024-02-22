#include <iostream>
#include <vector>

struct Node {
  int key;
  Node* right;
  Node* left;
  Node* parent;
};

Node* root;
Node* NIL;

void insert(int k) {
  Node* y = NIL;
  Node* x = root;
  Node* z = new Node;
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

void inorder(Node* u, std::ostream& out) {
  if (u == NIL) {
    return;
  }
  inorder(u->left, out);
  out << ' ' << u->key;
  inorder(u->right, out);
}

void preorder(Node* u, std::ostream& out) {
  if (u == NIL) {
    return;
  }
  out << ' ' << u->key;
  preorder(u->left, out);
  preorder(u->right, out);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  int n, x;
  std::string com;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> com;
    if (com == "insert") {
      std::cin >> x;
      insert(x);
    } else if (com == "print") {
      inorder(root, std::cout);
      std::cout << '\n';
      preorder(root, std::cout);
      std::cout << '\n';
    }
  }
  return 0;
}