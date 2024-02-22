#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
struct Node {
  int key;
  Node *parent, *left, *right;
};
Node *root, *NIL;
vector<Node> pool;
int pool_index = 0;
void insert(int k) {
  Node *y = NIL;
  Node *x = root;
  Node *z;
  if(pool_index < pool.size()) {
    z = &pool[pool_index++];
  } else {
    pool.push_back(Node());
    z = &pool.back();
  }
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
// The rest of the code remains the same