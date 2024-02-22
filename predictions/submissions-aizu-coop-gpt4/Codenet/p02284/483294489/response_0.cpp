#include <iostream>
#include <stack>
using namespace std;
struct Node {
  int key;
  Node *parent, *left, *right;
};
Node *root, *NIL;

void insert(int k) {
  // Insertion logic remains the same
}

bool find(int k) {
  // Find operation remains the same
}

void inorder(Node *u) {
  stack<Node*> s;
  Node *curr = u;
  
  while (curr != NIL || !s.empty()) {
    while (curr !=  NIL) {
      s.push(curr);
      curr = curr->left;
    }
    
    curr = s.top();
    s.pop();

    cout << " " << curr->key;

    curr = curr->right;
  }
}

void preorder(Node *u) {
  if (u == NIL)
    return;
    
  stack<Node*> s;
  s.push(u);
  
  while (!s.empty()) {
    Node *node = s.top();
    cout << " " << node->key;
    s.pop();

    if (node->right != NIL) {
      s.push(node->right);
    }
    if (node->left != NIL) {
      s.push(node->left);
    }
  }
}

int main() {
  // Main function remains the same
  return 0;
}