#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <utility>
#define INF (1 << 30)
using namespace std;

struct Node {
  int value;
  Node *left, *right;
  int priority;
  int cnt;
  int small;
  Node(int v) : value(v), priority(rand()), cnt(1), small(v) {
    left = right = nullptr;
  }
};
int count(Node *t) { return t ? t->cnt : 0; }
int mini(Node *t) { return t ? t->small : INF; }
Node *update(Node *t) {
  t->cnt = count(t->left) + count(t->right) + 1;
  t->small = min({mini(t->left), mini(t->right), t->value});
  return t;
}
Node *merge(Node *l, Node *r) {
  if (!l || !r)
    return l ? l : r;
  if (l->priority > r->priority) {
    l->right = merge(l->right, r);
    return update(l);
  } else {
    r->left = merge(l, r->left);
    return update(r);
  }
}
pair<Node *, Node *> split(Node *t, int k) {
  if (!t)
    return {nullptr, nullptr};
  if (k <= count(t->left)) {
    auto s = split(t->left, k);
    t->left = s.second;
    return {s.first, update(t)};
  } else {
    auto s = split(t->right, k - count(t->left) - 1);
    t->right = s.first;
    return {update(t), s.second};
  }
}
Node *insert(Node *t, int k, int val) {
  auto s = split(t, k);
  t = merge(s.first, new Node(val));
  return merge(t, s.second);
}
Node *erase(Node *t, int k) {
  auto s1 = split(t, k + 1);
  auto s2 = split(s1.first, k);
  return merge(s2.first, s1.second);
}
Node *find(Node *t, int k) {
  int c = count(t->left);
  if (k < c)
    return find(t->left, k);
  else if (k > c)
    return find(t->right, k - c - 1);
  else
    return t;
}
int rmq(Node *t, int l, int r) {
  if (l >= count(t) || r <= 0)
    return INF;
  if (l <= 0 && r >= count(t))
    return mini(t);
  int size = count(t->left);
  int ret = min(rmq(t->left, l, r), rmq(t->right, l - size - 1, r - size - 1));
  if (l <= size && size < r)
    ret = min(ret, t->value);
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  Node* root = nullptr;

  for (int i = 0, a; i < n; ++i) {
    cin >> a;
    root = insert(root, i, a);
  }

  while (q--) {
    int x, y, z;
    cin >> x >> y >> z;
    if (x == 0) {
      z++;
      auto c = split(root, z);
      auto b = split(c.first, z - 1);
      auto a = split(b.first, y);
      root = merge(a.first, b.second);
      root = merge(root, a.second);
      root = merge(root, c.second);
    } else if (x == 1) {
      cout << rmq(root, y, z + 1) << '\n';
    } else {
      root = erase(root, y);
      root = insert(root, y, z);
    }
  }

  return 0;
}