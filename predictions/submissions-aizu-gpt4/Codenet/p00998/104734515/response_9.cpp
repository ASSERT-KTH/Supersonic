#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define forsz(i, a) for (typeof((a).size()) i = 0; i < (a).size(); ++i)
#define IN(x, y) ((y).find((x)) != (y).end())
#define ISIN(x, y) (lower_bound(all(y), (x)) != (y).end() && *lower_bound(all(y), (x)) == (x))
#define debug(c) cerr << "> " << #c << " = " << c << "\n";
#define present(container, element) (container.find(element) != container.end())

struct Node {
  int val, sz;
  Node *l, *r;
  Node(int v) : val(v), sz(1), l(NULL), r(NULL) {}
};

int sz(Node *n) { return n ? n->sz : 0; }

void update_sz(Node *n) {
  if (n) n->sz = sz(n->l) + 1 + sz(n->r);
}

Node *merge(Node *l, Node *r) {
  if (!l) return r;
  if (!r) return l;
  if (rand() % (sz(l) + sz(r)) < sz(l)) {
    l->r = merge(l->r, r);
    update_sz(l);
    return l;
  } else {
    r->l = merge(l, r->l);
    update_sz(r);
    return r;
  }
}

pair<Node *, Node *> split(Node *n, int k) {
  if (!n) return {NULL, NULL};
  if (sz(n->l) >= k) {
    auto p = split(n->l, k);
    n->l = p.second;
    update_sz(n);
    return {p.first, n};
  } else {
    auto p = split(n->r, k - sz(n->l) - 1);
    n->r = p.first;
    update_sz(n);
    return {n, p.second};
  }
}

Node *insert(Node *n, int k, int val) {
  auto p = split(n, k);
  return merge(p.first, merge(new Node(val), p.second));
}

Node *erase(Node *n, int k) {
  auto p1 = split(n, k);
  auto p2 = split(p1.second, 1);
  delete p2.first;
  return merge(p1.first, p2.second);
}

int find(Node *n, int k) {
  if (sz(n->l) == k) return n->val;
  if (sz(n->l) > k) return find(n->l, k);
  return find(n->r, k - sz(n->l) - 1);
}

int rmq(Node *n, int l, int r) {
  if (l >= r) return 1e9;
  if (l <= 0 && r >= sz(n)) return n->val;
  int res = 1e9;
  if (l < sz(n->l)) res = min(res, rmq(n->l, l, min(r, sz(n->l))));
  if (r > sz(n->l)) res = min(res, rmq(n->r, max(0, l - sz(n->l) - 1), r - sz(n->l) - 1));
  if (l <= sz(n->l) && sz(n->l) < r) res = min(res, n->val);
  return res;
}

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  Node *root = NULL;
  while (n--) {
    int x;
    scanf("%d", &x);
    root = insert(root, sz(root), x);
  }
  while (q--) {
    int t, x, y;
    scanf("%d%d%d", &t, &x, &y);
    if (t == 0) {
      Node *a, *b, *c, *d;
      tie(a, b) = split(root, x);
      tie(c, d) = split(b, y - x + 1);
      root = merge(merge(a, d), c);
    } else if (t == 1) {
      printf("%d\n", rmq(root, x, y + 1));
    } else {
      root = insert(erase(root, x), x, y);
    }
  }
}