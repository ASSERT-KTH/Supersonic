#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
const int MAX_N = 100000;
struct Treap {
  struct node {
    int value;
    int left, right;
    int priority;
    int cnt;
    int small;
    node(int v) : value(v), priority(rand()), cnt(1), small(v) {
      left = right = -1;
    }
  };
  node tree[MAX_N];
  int root;
  int size;
  Treap() : root(-1), size(0) {}
  int count(int t) { return (t == -1) ? 0 : tree[t].cnt; }
  int mini(int t) { return (t == -1) ? INF : tree[t].small; }
  void update(int t) {
    tree[t].cnt = count(tree[t].left) + count(tree[t].right) + 1;
    tree[t].small = min(min(mini(tree[t].left), mini(tree[t].right)), tree[t].value);
  }
  int merge(int l, int r) {
    if (l == -1 || r == -1)
      return (l == -1) ? r : l;
    if (tree[l].priority > tree[r].priority) {
      tree[l].right = merge(tree[l].right, r);
      update(l);
      return l;
    } else {
      tree[r].left = merge(l, tree[r].left);
      update(r);
      return r;
    }
  }
  pair<int, int> split(int t, int k) {
    if (t == -1)
      return make_pair(-1, -1);
    if (k <= count(tree[t].left)) {
      pair<int, int> s = split(tree[t].left, k);
      tree[t].left = s.second;
      update(t);
      return make_pair(s.first, t);
    } else {
      pair<int, int> s = split(tree[t].right, k - count(tree[t].left) - 1);
      tree[t].right = s.first;
      update(t);
      return make_pair(t, s.second);
    }
  }
  int insert(int t, int k, int val) {
    pair<int, int> s = split(t, k);
    int newNode = size++;
    tree[newNode] = node(val);
    t = merge(merge(s.first, newNode), s.second);
    return t;
  }
  int erase(int t, int k) {
    pair<int, int> s1, s2;
    s1 = split(t, k + 1);
    s2 = split(s1.first, k);
    t = merge(s2.first, s1.second);
    return t;
  }
  int find(int t, int k) {
    int c = count(tree[t].left);
    if (k < c)
      return find(tree[t].left, k);
    else if (k > c)
      return find(tree[t].right, k - c - 1);
    else
      return t;
  }
  int rmq(int t, int l, int r) {
    if (l >= count(t) || r <= 0)
      return INF;
    if (l <= 0 && r >= count(t))
      return mini(t);
    int size = count(tree[t].left);
    int ret =
        min(rmq(tree[t].left, l, r), rmq(tree[t].right, l - size - 1, r - size - 1));
    if (l <= size && size < r)
      ret = min(ret, tree[t].value);
    return ret;
  }
  void insert(int k, int v) { root = insert(root, k, v); }
  void erase(int k) { root = erase(root, k); }
  int find(int k) { return find(root, k); }
  int rmq(int l, int r) { return rmq(root, l, r); }
};
int main() {
  int n, q;
  Treap tree;
  scanf("%d %d", &n, &q);
  for (int i = 0, a; i < n; i++) {
    scanf("%d", &a);
    tree.insert(i, a);
  }
  while (q--) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    if (x == 0) {
      z++;
      pair<int, int> a, b, c;
      c = tree.split(tree.root, z);
      b = tree.split(c.first, z - 1);
      a = tree.split(b.first, y);
      tree.root = tree.merge(tree.merge(a.first, b.second), tree.merge(a.second, c.second));
    } else if (x == 1) {
      cout << tree.rmq(y, z + 1) << endl;
    } else {
      tree.erase(y);
      tree.insert(y, z);
    }
  }
}