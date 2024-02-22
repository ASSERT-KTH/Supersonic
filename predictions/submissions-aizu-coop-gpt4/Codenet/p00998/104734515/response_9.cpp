#include <iostream>
#include <algorithm>
#include <cstdlib>
// Use '-O2' compiler flag for optimization

using namespace std;

const int INF = 1 << 30;

struct NodePair {
  node *first, *second;
};

struct Treap {
  struct node {
    int value;
    node *left, *right;
    int priority;
    int cnt;
    int small;
    node(int v) : value(v), priority(rand()), cnt(1), small(v) {
      left = right = NULL;
    }
  };
  node *root;
  Treap() : root(NULL) {}

  int count(node *t) { return !t ? 0 : t->cnt; }
  int mini(node *t) { return !t ? INF : t->small; }
  node *update(node *t) {
    int cnt_left = count(t->left);
    int cnt_right = count(t->right);
    t->cnt = cnt_left + cnt_right + 1;
    int mini_left = mini(t->left);
    int mini_right = mini(t->right);
    t->small = min(min(mini_left, mini_right), t->value);
    return t;
  }
  // Remaining code...
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  // Remaining code...
}