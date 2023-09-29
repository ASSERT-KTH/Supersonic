#include <bits/stdc++.h>
using namespace std;
template <class Key> struct RandomizedBinarySearchTree {
  inline int xor128() {
    static int x = 123456789;
    static int y = 362436069;
    static int z = 521288629;
    static int w = 88675123;
    int t;
    t = x ^ (x << 11);
    x = y;
    y = z;
    z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
  }
  struct Node {
    Node *l, *r;
    int cnt;
    Key key;
    Node() {}
    Node(const Key &k) : cnt(1), key(k), l(nullptr), r(nullptr) {}
  };
  vector<Node> pool;
  int ptr;
  RandomizedBinarySearchTree(int sz) : pool(sz), ptr(0) {}
  inline Node *alloc(const Key &key) { return &(pool[ptr++] = Node(key)); }
  virtual Node *clone(Node *t) { return t; }
  inline int count(const Node *t) { return t ? t->cnt : 0; }
  inline Node *update(Node *t) {
    t->cnt = count(t->l) + count(t->r) + 1;
    return t;
  }
  Node *propagete(Node *t) { return update(clone(t)); }
  Node *merge(Node *l, Node *r) {
    if (!l || !r)
      return l ? l : r;
    if ((xor128() % (l->cnt + r->cnt)) < l->cnt) {
      l = propagete(l);
      l->r = merge(l->r, r);
      return update(l);
    } else {
      r = propagete(r);
      r->l = merge(l, r->l);
      return update(r);
    }
  }
  pair<Node *, Node *> split(Node *t, int k) {
    if (!t)
      return {t, t};
    t = propagete(t);
    if (k <= count(t->l)) {
      auto s = split(t->l, k);
      t->l = s.second;
      return {s.first, update(t)};
    } else {
      auto s = split(t->r, k - count(t->l) - 1);
      t->r = s.first;
      return {update(t), s.second};
    }
  }
  Node *build(int l, int r, const vector<Key> &v) {
    if (l + 1 >= r)
      return alloc(v[l]);
    return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));
  }
  Node *build(const vector<Key> &v) {
    ptr = 0;
    return build(0, (int)v.size(), v);
  }
  void dump(Node *r, typename vector<Key>::iterator &it) {
    if (!r)
      return;
    r = propagete(r);
    dump(r->l, it);
    *it = r->key;
    dump(r->r, ++it);
  }
  vector<Key> dump(Node *r) {
    vector<Key> v((size_t)count(r));
    auto it = begin(v);
    dump(r, it);
    return v;
  }
  string to_string(Node *r) {
    auto s = dump(r);
    string ret;
    for (int i = 0; i < s.size(); i++)
      ret += ", ";
    return (ret);
  }
  void insert(Node *&t, int k, const Key &v) {
    auto x = split(t, k);
    t = merge(merge(x.first, alloc(v)), x.second);
  }
  void erase(Node *&t, int k) {
    auto x = split(t, k);
    t = merge(x.first, split(x.second, 1).second);
  }
  int size(Node *t) { return count(t); }
  bool empty(Node *t) { return !t; }
  Node *makeset() { return (nullptr); }
};
template <class Key>
struct PresidentRandomizedBinarySearchTree : RandomizedBinarySearchTree<Key> {
  using RBST = RandomizedBinarySearchTree<Key>;
  using Node = typename RBST::Node;
  PresidentRandomizedBinarySearchTree(int sz) : RBST(sz) {}
  Node *clone(Node *t) override { return &(RBST::pool[RBST::ptr++] = *t); }
  Node *rebuild(Node *r) { return RBST::build(RBST::dump(r)); }
};
template <class T>
struct OrderedMultiSet : PresidentRandomizedBinarySearchTree<T> {
  using RBST = PresidentRandomizedBinarySearchTree<T>;
  using Node = typename RBST::Node;
  OrderedMultiSet(int sz) : RBST(sz) {}
  T kth_element(Node *t, int k) {
    if (k < RBST::count(t->l))
      return kth_element(t->l, k);
    if (k == RBST::count(t->l))
      return t->key;
    return kth_element(t->r, k - RBST::count(t->l) - 1);
  }
  virtual void insert_key(Node *&t, const T &x) {
    RBST::insert(t, lower_bound(t, x), x);
  }
  void erase_key(Node *&t, const T &x) {
    if (!count(t, x))
      return;
    RBST::erase(t, lower_bound(t, x));
  }
  int count(Node *t, const T &x) {
    return upper_bound(t, x) - lower_bound(t, x);
  }
  int lower_bound(Node *t, const T &x) {
    if (!t)
      return 0;
    if (x <= t->key)
      return lower_bound(t->l, x);
    return lower_bound(t->r, x) + RBST::count(t->l) + 1;
  }
  int upper_bound(Node *t, const T &x) {
    if (!t)
      return 0;
    if (x < t->key)
      return upper_bound(t->l, x);
    return upper_bound(t->r, x) + RBST::count(t->l) + 1;
  }
};
struct CentroidPathDecomposition {
  struct Centroid {
    int ParIndex, ParDepth, Deep;
    vector<int> node;
    Centroid(int idx, int dep, int deep)
        : ParIndex(idx), ParDepth(dep), Deep(deep) {}
    inline size_t size() { return (node.size()); }
    inline int &operator[](int k) { return (node[k]); }
    inline pair<int, int> Up() { return (make_pair(ParIndex, ParDepth)); }
  };
  vector<vector<int>> graph;
  vector<int> SubTreeSize, NextPath;
  vector<int> TreeIndex, TreeDepth;
  vector<Centroid> Centroids;
  void BuildSubTreeSize() {
    stack<pair<int, int>> s;
    s.emplace(0, -1);
    while (!s.empty()) {
      auto p = s.top();
      s.pop();
      if (~SubTreeSize[p.first]) {
        NextPath[p.first] = -1;
        for (auto &to : graph[p.first]) {
          if (p.second == to)
            continue;
          SubTreeSize[p.first] += SubTreeSize[to];
          if (NextPath[p.first] == -1 ||
              SubTreeSize[NextPath[p.first]] < SubTreeSize[to]) {
            NextPath[p.first] = to;
          }
        }
      } else {
        s.push(p);
        SubTreeSize[p.first] = 1;
        for (auto &to : graph[p.first]) {
          if (p.second != to)
            s.emplace(to, p.first);
        }
      }
    }
  }
  void BuildPath() {
    stack<pair<int, int>> s;
    Centroids.emplace_back(-1, -1, 0);
    s.emplace(0, -1);
    TreeIndex[0] = 0;
    while (!s.empty()) {
      auto p = s.top();
      s.pop();
      TreeDepth[p.first] = (int)Centroids[TreeIndex[p.first]].size();
      for (auto &to : graph[p.first]) {
        if (p.second == to)
          continue;
        if (to == NextPath[p.first]) {
          TreeIndex[to] = TreeIndex[p.first];
        } else {
          TreeIndex[to] = (int)Centroids.size();
          Centroids.emplace_back(TreeIndex[p.first], TreeDepth[p.first],
                                 Centroids[TreeIndex[p.first]].Deep + 1);
        }
        s.emplace(to, p.first);
      }
      Centroids[TreeIndex[p.first]].node.emplace_back(p.first);
    }
  }
  void AddEdge(int x, int y) {
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  virtual void Build() {
    BuildSubTreeSize();
    BuildPath();
  }
  inline size_t size() { return (Centroids.size()); }
  inline pair<int, int> Information(int idx) {
    return (make_pair(TreeIndex[idx], TreeDepth[idx]));
  }
  inline Centroid &operator[](int k) { return (Centroids[k]); }
  inline int LCA(int a, int b) {
    int TreeIdxA, TreeDepthA, TreeIdxB, TreeDepthB;
    tie(TreeIdxA, TreeDepthA) = Information(a);
    tie(TreeIdxB, TreeDepthB) = Information(b);
    while (TreeIdxA != TreeIdxB) {
      if (Centroids[TreeIdxA].Deep > Centroids[TreeIdxB].Deep) {
        tie(TreeIdxA, TreeDepthA) = Centroids[TreeIdxA].Up();
      } else {
        tie(TreeIdxB, TreeDepthB) = Centroids[TreeIdxB].Up();
      }
    }
    if (TreeDepthA > TreeDepthB)
      swap(TreeDepthA, TreeDepthB);
    return (Centroids[TreeIdxA][TreeDepthA]);
  }
  inline virtual void query(int a, int b,
                            const function<void(int, int, int)> &f) {
    int TreeIdxA, TreeDepthA, TreeIdxB, TreeDepthB;
    tie(TreeIdxA, TreeDepthA) = Information(a);
    tie(TreeIdxB, TreeDepthB) = Information(b);
    while (TreeIdxA != TreeIdxB) {
      if (Centroids[TreeIdxA].Deep > Centroids[TreeIdxB].Deep) {
        f(TreeIdxA, 0, TreeDepthA + 1);
        tie(TreeIdxA, TreeDepthA) = Centroids[TreeIdxA].Up();
      } else {
        f(TreeIdxB, 0, TreeDepthB + 1);
        tie(TreeIdxB, TreeDepthB) = Centroids[TreeIdxB].Up();
      }
    }
    if (TreeDepthA > TreeDepthB)
      swap(TreeDepthA, TreeDepthB);
    f(TreeIdxA, TreeDepthA, TreeDepthB + 1);
  }
  CentroidPathDecomposition(int SZ) {
    graph.resize(SZ);
    SubTreeSize.assign(SZ, -1);
    NextPath.resize(SZ);
    TreeIndex.resize(SZ);
    TreeDepth.resize(SZ);
  }
};
OrderedMultiSet<int> tree(5000000);
OrderedMultiSet<int>::Node *nodes[100000];
int N, Q, X[100000];
vector<int> g[100000];
int parent[100000];
void dfs(int idx, int par, OrderedMultiSet<int>::Node *par_set) {
  parent[idx] = par;
  tree.insert_key(par_set, X[idx]);
  nodes[idx] = par_set;
  for (auto &to : g[idx])
    if (to != par)
      dfs(to, idx, par_set);
}
int main() {
  scanf("%d %d", &N, &Q);
  CentroidPathDecomposition gg(N);
  vector<int> vs;
  for (int i = 0; i < N; i++) {
    scanf("%d", &X[i]);
    vs.emplace_back(X[i]);
  }
  sort(begin(vs), end(vs));
  vs.erase(unique(begin(vs), end(vs)), end(vs));
  for (int i = 1; i < N; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x, --y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
    gg.AddEdge(x, y);
  }
  dfs(0, -1, tree.makeset());
  gg.Build();
  for (int i = 0; i < Q; i++) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    --x, --y;
    int lca = gg.LCA(x, y);
    int ng = -1, ok = (int)vs.size() - 1;
    auto sum = [&](int v) {
      int ret = 0;
      ret += tree.upper_bound(nodes[x], vs[v]);
      ret += tree.upper_bound(nodes[y], vs[v]);
      ret -= tree.upper_bound(nodes[lca], vs[v]);
      if (lca)
        ret -= tree.upper_bound(nodes[parent[lca]], vs[v]);
      return ret;
    };
    while (ok - ng > 1) {
      int mid = (ok + ng) >> 1;
      if (sum(mid) >= z)
        ok = mid;
      else
        ng = mid;
    }
    printf("%d\n", vs[ok]);
  }
}
