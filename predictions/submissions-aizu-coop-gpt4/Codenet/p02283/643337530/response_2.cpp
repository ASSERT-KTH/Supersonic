#include <iostream>
#include <memory>
#include <string>

struct Node {
  int key;
  std::unique_ptr<Node> right, left;
  Node* parent = nullptr;
  
  Node(int k) : key(k), right(nullptr), left(nullptr), parent(nullptr) {}
};

class BST {
private:
  std::unique_ptr<Node> root;

public:
  void insert(int k) {
    Node* y = nullptr;
    Node* x = root.get();
    auto z = std::make_unique<Node>(k);
    while (x != nullptr) {
      y = x;
      if (z->key < x->key) {
        x = x->left.get();
      } else {
        x = x->right.get();
      }
    }
    z->parent = y;
    if (y == nullptr) {
      root = std::move(z); // tree was empty
    } else if (z->key < y->key) {
      y->left = std::move(z);
    } else {
      y->right = std::move(z);
    }
  }

  void inorder(Node* u) {
    if (u == nullptr)
      return;
    inorder(u->left.get());
    std::cout << " " << u->key;
    inorder(u->right.get());
  }

  void preorder(Node* u) {
    if (u == nullptr)
      return;
    std::cout << " " << u->key;
    preorder(u->left.get());
    preorder(u->right.get());
  }

  void print() {
    inorder(root.get());
    std::cout << "\n";
    preorder(root.get());
    std::cout << "\n";
  }
};

int main() {
  BST bst;
  int n;
  std::string command;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> command;
    if (command == "insert") {
      int x;
      std::cin >> x;
      bst.insert(x);
    } else if (command == "print") {
      bst.print();
    }
  }
  return 0;
}