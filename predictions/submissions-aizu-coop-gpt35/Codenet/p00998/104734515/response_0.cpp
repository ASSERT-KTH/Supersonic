#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
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
  vector<node> nodes;
  vector<int> priorities;
  int root;
  Treap() : root(-1) {}
  int count(int t) { return t == -1 ? 0 : nodes[t].cnt; }
  int mini(int t) { return t == -1 ? INF : nodes[t].small; }
  void update(int t) {
    if (t == -1) return;
    nodes[t].cnt = count(nodes[t].left) + count(nodes[t].right) + 1;
    nodes[t].small = min(min(mini(nodes[t].left), mini(nodes[t].right)), nodes[t].value);
  }
  int merge(int l, int r) {
    if (l == -1 || r == -1)
      return l == -1 ? r : l;
    if (nodes[l].priority > nodes[r].priority) {
      nodes[l].right = merge(nodes[l].right, r);
      update(l);
      return l;
    } else {
      nodes[r].left = merge(l, nodes[r].left);
      update(r);
      return r;
    }
  }
  pair<int, int> split(int t, int k) {
    if (t == -1)
      return make_pair(-1, -1);
    if (k <= count(nodes[t].left)) {
      pair<int, int> s = split(nodes[t].left, k);
      nodes[t].left = s.second;
      update(t);
      return make_pair(s.first, t);
    } else {
      pair<int, int> s = split(nodes[t].right, k - count(nodes[t].left) - 1);
      nodes[t].right = s.first;
      update(t);
      return make_pair(t, s.second);
    }
  }
  int insert(int t, int k, int val) {
    pair<int, int> s = split(t, k);
    nodes.push_back(node(val));
    int new_node = nodes.size() - 1;
    t = merge(merge(s.first, new_node), s.second);
    update(t);
    return t;
  }
  int erase(int t, int k) {
    pair<int, int> s1, s2;
    s1 = split(t, k + 1);
    s2 = split(s1.first, k);
    t = merge(s2.first, s1.second);
    update(t);
    return t;
  }
  int find(int t, int k) {
    if (t == -1) return -1;
    int c = count(nodes[t].left);
    if (k < c)
      return find(nodes[t].left, k);
    else if (k > c)
      return find(nodes[t].right, k - c - 1);
    else
      return t;
  }
  int rmq(int t, int l, int r) {
    if (t == -1 || l >= count(t) || r <= 0)
      return INF;
    if (l <= 0 && r >= count(t))
      return mini(t);
    int size = count(nodes[t].left);
    int ret =
        min(rmq(nodes[t].left, l, r), rmq(nodes[t].right, l - size - 1, r - size - 1));
    if (l <= size && size < r)
      ret = min(ret, nodes[t].value);
    return ret;
  }
  void insert(int k, int v) { root = insert(root, k, v); }
  void erase(int k) { root = erase(root, k); }
  int find(int k) { return find(root, k); }
  int rmq(int l, int r) { return rmq(root, l, r); }
};
int main() {
  #pragma GCC optimize("O3")
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
      tree.root = tree.merge(a.first, b.second);
      tree.root = tree.merge(tree.root, a.second);
      tree.root = tree.merge(tree.root, c.second);
    } else if (x == 1) {
      cout << tree.rmq(y, z + 1) << endl;
    } else {
      tree.erase(y);
      tree.insert(y, z);
    }
  }
}