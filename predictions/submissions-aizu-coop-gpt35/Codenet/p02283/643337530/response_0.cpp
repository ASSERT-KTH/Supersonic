#include <iostream>
#include <memory>
#include <string>

struct Node {
  int key;
  std::shared_ptr<Node> left, right;
  std::weak_ptr<Node> parent;
};

std::shared_ptr<Node> root;
std::shared_ptr<Node> NIL;

void insert(int k) {
  std::shared_ptr<Node> y = NIL;
  std::shared_ptr<Node> x = root;
  std::shared_ptr<Node> z = std::make_shared<Node>();
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

void inorder(const std::shared_ptr<Node>& u) {
  if (u == NIL)
    return;
  inorder(u->left);
  std::cout << " " << u->key;
  inorder(u->right);
}

void preorder(const std::shared_ptr<Node>& u) {
  if (u == NIL)
    return;
  std::cout << " " << u->key;
  preorder(u->left);
  preorder(u->right);
}

int main() {
  int n, x;
  std::string com;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> com;
    if (com == "insert") {
      std::cin >> x;
      insert(x);
    } else if (com == "print") {
      inorder(root);
      std::cout << std::endl;
      preorder(root);
      std::cout << std::endl;
    }
  }
  return 0;
}