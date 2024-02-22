#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
  int key;
  Node *parent, *left, *right;
};

Node *root, *NIL;
unordered_set<int> keys;

void insert(int& k) {
  keys.insert(k);
}

bool find(const int k) {
  return keys.find(k) != keys.end();
}

void inorder(Node *u) {
  if (u == NIL)
    return;
  inorder(u->left);
  cout << " " << u->key;
  inorder(u->right);
}

void preorder(Node *u) {
  if (u == NIL)
    return;
  cout << " " << u->key;
  preorder(u->left);
  preorder(u->right);
}

int main() {
  int x;
  string com;
  cin >> x;
  for (int i = 0; i < x; i++) {
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