#include <iostream>
#include <stack>

struct Node {
  int key;
  Node *parent, *left, *right;
};

const int MAX_NODES = 100000;
Node nodes[MAX_NODES];
int nodeIndex = 0;

Node* createNode(int key) {
  Node* node = &nodes[nodeIndex++];
  node->key = key;
  node->parent = nullptr;
  node->left = nullptr;
  node->right = nullptr;
  return node;
}

Node *root = nullptr;

void insert(int k) {
  Node *y = nullptr;
  Node *x = root;
  Node *z = createNode(k);
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
}

bool find(int k) {
  Node *v = root;
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

void inorder(Node *u) {
  std::stack<Node*> s;
  Node* curr = u;
  while (curr != nullptr || !s.empty()) {
    while (curr != nullptr) {
      s.push(curr);
      curr = curr->left;
    }
    curr = s.top();
    s.pop();
    std::cout << " " << curr->key;
    curr = curr->right;
  }
}

void preorder(Node *u) {
  if (u == nullptr)
    return;
  std::stack<Node*> s;
  s.push(u);
  while (!s.empty()) {
    Node* curr = s.top();
    s.pop();
    std::cout << " " << curr->key;
    if (curr->right != nullptr)
      s.push(curr->right);
    if (curr->left != nullptr)
      s.push(curr->left);
  }
}

int main() {
  int n, x;
  char com[10];
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> com;
    if (com[0] == 'i') {
      std::cin >> x;
      insert(x);
    } else if (com[0] == 'p') {
      inorder(root);
      std::cout << std::endl;
      preorder(root);
      std::cout << std::endl;
    } else if (com[0] == 'f') {
      std::cin >> x;
      if (find(x))
        std::cout << "yes" << std::endl;
      else
        std::cout << "no" << std::endl;
    }
  }
  return 0;
}