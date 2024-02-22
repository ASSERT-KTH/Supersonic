#include <iostream>
#include <string>

struct Node {
  int key;
  Node* parent;
  Node* left;
  Node* right;
};

Node* root;
Node* NIL;

void insertHelper(Node*& node, int k, Node* parent) {
  if (node == NIL) {
    node = new Node;
    node->key = k;
    node->parent = parent;
    node->left = NIL;
    node->right = NIL;
  } else if (k < node->key) {
    insertHelper(node->left, k, node);
  } else {
    insertHelper(node->right, k, node);
  }
}

void insert(int k) {
  insertHelper(root, k, NIL);
}

bool findHelper(Node* node, int k) {
  if (node == NIL) {
    return false;
  } else if (k == node->key) {
    return true;
  } else if (k < node->key) {
    return findHelper(node->left, k);
  } else {
    return findHelper(node->right, k);
  }
}

bool find(int k) {
  return findHelper(root, k);
}

void inorder(const Node& u) {
  if (&u == NIL)
    return;
  inorder(*u.left);
  std::cout << " " << u.key;
  inorder(*u.right);
}

void preorder(const Node& u) {
  if (&u == NIL)
    return;
  std::cout << " " << u.key;
  preorder(*u.left);
  preorder(*u.right);
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
      inorder(*root);
      std::cout << std::endl;
      preorder(*root);
      std::cout << std::endl;
    } else if (com == "find") {
      std::cin >> x;
      if (find(x))
        std::cout << "yes" << std::endl;
      else
        std::cout << "no" << std::endl;
    }
  }
  return 0;
}