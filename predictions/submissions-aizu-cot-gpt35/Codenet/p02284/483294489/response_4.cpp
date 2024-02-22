#include <iostream>
#include <string>
#include <unordered_set>

struct Node {
  int key;
  Node* parent;
  Node* left;
  Node* right;
};

Node* root = nullptr;
std::unordered_set<int> keys;

void insert(int k) {
  Node* y = nullptr;
  Node* x = root;
  Node* z = new Node;
  z->key = k;
  z->left = nullptr;
  z->right = nullptr;
  
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
  } else {
    if (z->key < y->key)
      y->left = z;
    else
      y->right = z;
  }
  
  keys.insert(k);
}

void inorder(Node* u) {
  std::cout << " ";
  Node* current = u;
  std::stack<Node*> stack;
  
  while (current != nullptr || !stack.empty()) {
    while (current != nullptr) {
      stack.push(current);
      current = current->left;
    }
    
    current = stack.top();
    stack.pop();
    
    std::cout << current->key;
    
    current = current->right;
  }
}

void preorder(Node* u) {
  std::cout << " ";
  Node* current = u;
  std::stack<Node*> stack;
  
  while (current != nullptr || !stack.empty()) {
    while (current != nullptr) {
      std::cout << current->key;
      stack.push(current);
      current = current->left;
    }
    
    current = stack.top();
    stack.pop();
    
    current = current->right;
  }
}

bool find(int k) {
  return keys.find(k) != keys.end();
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