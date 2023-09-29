#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define all(c) begin(c), end(c)
const int INF =
    sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
template <class T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T> bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
using Weight = int;
struct Edge {
  int s, d;
  Weight w;
  Edge(int s, int d, Weight w = 1) : s(s), d(d), w(w){};
  bool operator<(const Edge &e) const { return w < e.w; }
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;
struct LowestCommonAncestor {
  const int n, log2_n;
  vector<vector<int>> parent;
  vector<int> depth;
  LowestCommonAncestor(const Graph &g, const int root)
      : n(g.size()), log2_n(log2(n) + 1), parent(log2_n, vector<int>(n)),
        depth(n) {
 