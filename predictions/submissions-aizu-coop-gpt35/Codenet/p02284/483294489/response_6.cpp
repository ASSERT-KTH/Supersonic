#include <cstdio>
#include <iostream>
#include <sstream>
using namespace std;

const int MAX_NODES = 100000; // Maximum number of nodes in the BST

struct BST {
  struct Node {
    int key;
    int parent, left, right;
  };

  Node nodes[MAX_NODES];
  int root;

  BST() {
    root = -1; // Initialize the BST as empty
  }

  int allocateNode() {
    for (int i = 0; i < MAX_NODES; i++) {
      if (nodes[i].parent == -1) {
        return i; // Return the index of the first available node
      }
    }
    return -1; // No available nodes
  }

  void insert(int k) {
    int y = -1;
    int x = root;
    int z = allocateNode();
    if (z == -1) {
      return; // No available nodes
    }
    nodes[z].key = k;
    nodes[z].left = -1;
    nodes[z].right = -1;
    while (x != -1) {
      y = x;
      if (z->key < nodes[x].key) {
        x = nodes[x].left;
      } else {
        x = nodes[x].right;
      }
    }
    nodes[z].parent = y;
    if (y == -1) {
      root = z;
    } else {
      if (z->key < nodes[y].key)
        nodes[y].left = z;
      else
        nodes[y].right = z;
    }
  }

  bool find(int k) {
    int x = root;
    while (x != -1) {
      int currentKey = nodes[x].key;
      if (k == currentKey)
        return true;
      if (k < currentKey) {
        x = nodes[x].left;
      } else {
        x = nodes[x].right;
      }
    }
    return false;
  }

  void inorder(int u, stringstream& ss) {
    if (u == -1)
      return;
    inorder(nodes[u].left, ss);
    ss << " " << nodes[u].key;
    inorder(nodes[u].right, ss);
  }

  void preorder(int u, stringstream& ss) {
    if (u == -1)
      return;
    ss << " " << nodes[u].key;
    preorder(nodes[u].left, ss);
    preorder(nodes[u].right, ss);
  }
};

int main() {
  int n, x;
  string com;
  cin >> n;

  BST bst;

  for (int i = 0; i < n; i++) {
    cin >> com;
    if (com == "insert") {
      cin >> x;
      bst.insert(x);
    } else if (com == "print") {
      stringstream ss;
      bst.inorder(bst.root, ss);
      ss << endl;
      bst.preorder(bst.root, ss);
      ss << endl;
      cout << ss.str();
    } else if (com == "find") {
      cin >> x;
      if (bst.find(x))
        cout << "yes" << endl;
      else
        cout << "no" << endl;
    }
  }
  return 0;
}