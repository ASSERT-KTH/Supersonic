#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
  int key;
  Node *parent, *left, *right;
};

Node *root, *NIL;
Node nodePool[5000000];  // assuming max number of nodes to be inserted
int nodeCnt = 0;

void insert(int k) {
  Node *y = NIL;
  Node *x = root;
  Node *z = &nodePool[nodeCnt++];
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
    if (z->key < y->key)
      y->left = z;
    else
      y->right = z;
  }
}

// Other functions remain the same...

int main() {
  unordered_map<string, int> command_mapping = {{"insert", 1}, {"print", 2}, {"find", 3}};
  int n, x;
  string com;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> com;
    switch (command_mapping[com]) {
      case 1:
        cin >> x;
        insert(x);
        break;
      case 2:
        inorder(root);
        cout << endl;
        preorder(root);
        cout << endl;
        break;
      case 3:
        cin >> x;
        if (find(x))
          cout << "yes" << endl;
        else
          cout << "no" << endl;
        break;
    }
  }
  return 0;
}