#include <cstdio>
#include <cstdlib>
#include <algorithm>
using std::min;
using std::pair;
using std::make_pair;

const int INF = 1 << 30;

struct Node {
  int value, priority, cnt, small;
  Node *left, *right;
  Node(int v) : value(v), priority(rand()), cnt(1), small(v) {
    left = right = NULL;
  }
};

inline int count(Node *t) { return t ? t->cnt : 0; }

inline int mini(Node *t) { return t ? t->small : INF; }

Node *update(Node *t) {
  if (t) {
    t->cnt = count(t->left) + count(t->right) + 1;
    t->small = min(min(mini(t->left), mini(t->right)), t->value);
  }
  return t;
}

Node *merge(Node *l, Node *r);
pair<Node *, Node *> split(Node *t, int k);
Node *insert(Node *t, int k, int val);
Node *erase(Node *t, int k);
Node *find(Node *t, int k);
int rmq(Node *t, int l, int r);

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
    return make_pair((Node *)NULL, (Node *)NULL);
  if (k <= count(t->left)) {
    pair<Node *, Node *> s = split(t->left, k);
    t->left = s.second;
    return make_pair(s.first, update(t));
  } else {
    pair<Node *, Node *> s = split(t->right, k - count(t->left) - 1);
    t->right = s.first;
    return make_pair(update(t), s.second);
  }
}

Node *insert(Node *t, int k, int val) {
  pair<Node *, Node *> s = split(t, k);
  t = merge(s.first, new Node(val));
  return update(merge(t, s.second));
}

Node *erase(Node *t, int k) {
  pair<Node *, Node *> s1, s2;
  s1 = split(t, k + 1);
  s2 = split(s1.first, k);
  t = merge(s2.first, s1.second);
  return update(t);
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
  int ret =
      min(rmq(t->left, l, r), rmq(t->right, l - size - 1, r - size - 1));
  if (l <= size && size < r)
    ret = min(ret, t->value);
  return ret;
}

int main() {
  int n, q;
  Node *root = NULL;
  scanf("%d %d", &n, &q);
  for (int i = 0, a; i < n; i++) {
    scanf("%d", &a);
    root = insert(root, i, a);
  }
  while (q--) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    if (x == 0) {
      z++;
      pair<Node *, Node *> a, b, c;
      c = split(root, z);
      b = split(c.first, z - 1);
      a = split(b.first, y);
      root = merge(merge(a.first, b.second), merge(a.second, c.second));
    } else if (x == 1) {
      printf("%d\n", rmq(root, y, z + 1));
    } else {
      root = erase(root, y);
      root = insert(root, y, z);
    }
  }
  return 0;
}