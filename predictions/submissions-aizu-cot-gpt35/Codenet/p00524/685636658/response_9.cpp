#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <cassert>
using namespace std;
using ll = long long;
#define rep(i, n) for (int& i = n; (i) < (int)(n); ++(i))
#define pb push_back
#define fi first
#define se second
using pi = pair<int, int>;
using P = pair<ll, int>;
struct edge {
  int to;
  ll cost;
};
const int V = 100000;
const int VV = 1000000;
const ll INF = LLONG_MAX / 3;
vector<edge> G[V];
vector<vector<pi>> gg(VV);
vector<vector<int>> height(V);
int n, m;
ll X;
int H[V];
vector<int> v2id(2 * V * V);
int max_h[V] = {};
vector<ll> d(VV);
int main() {
  scanf(" %d %d %lld", &n, &m, &X);
  rep(i, n) scanf(" %d", &H[i]);
  rep(i, m) {
    int a, b, t;
    scanf(" %d %d %d", &a, &b, &t);
    --a;
    --b;
    G[a].pb({b, t});
    G[b].pb({a, t});
  }
  int ct = 1;
  vector<pi> que;
  que.pb(pi(X, 0));
  v2id[pi(0, X)] = 0;
  max_h[0] = X;
  height[0].pb(X);
  for (int i = 0; i < que.size(); ++i) {
    pi p = que[i];
    int v = p.se, h = p.fi;
    if (h < max_h[v])
      continue;
    for (const auto &e : G[v]) {
      int bh = h;
      int nh = h - e.cost;
      if (nh < 0)
        continue;
      if (nh > H[e.to]) {
        bh = H[e.to] + e.cost;
        nh = H[e.to];
      }
      if (nh > max_h[e.to]) {
        if (!v2id[pi(v, bh)]) {
          v2id[pi(v, bh)] = ct++;
          height[v].pb(bh);
        }
        if (!v2id[pi(e.to, nh)]) {
          v2id[pi(e.to, nh)] = ct++;
          height[e.to].pb(nh);
        }
        int uu = v2id[pi(v, bh)], vv = v2id[pi(e.to, nh)];
        gg[uu].pb({vv, e.cost});
        max_h[e.to] = nh;
        que.pb(pi(max_h[e.to], e.to));
      }
    }
  }
  rep(i, n) for (const auto &e : G[i]) {
    if (H[i] < e.cost)
      continue;
    if (!v2id[pi(i, e.cost)]) {
      v2id[pi(i, e.cost)] = ct++;
      height[i].pb(e.cost);
    }
    if (!v2id[pi(e.to, 0)]) {
      v2id[pi(e.to, 0)] = ct++;
      height[e.to].pb(0);
    }
    int uu = v2id[pi(i, e.cost)];
    int vv = v2id[pi(e.to, 0)];
    gg[uu].pb({vv, e.cost});
  }
  if (!v2id[pi(n - 1, H[n - 1])]) {
    v2id[pi(n - 1, H[n - 1])] = ct++;
    height[n - 1].pb(H[n - 1]);
  }
  rep(i, n) {
    int S = height[i].size();
    auto itr = height[i].begin();
    rep(j, S - 1) {
      auto nx = itr;
      ++nx;
      assert(v2id[pi(i, *itr)]);
      assert(v2id[pi(i, *nx)]);
      int uu = v2id[pi(i, *itr)];
      int vv = v2id[pi(i, *nx)];
      int dist = *nx - *itr;
      gg[uu].pb({vv, dist});
      gg[vv].pb({uu, dist});
      itr = nx;
    }
  }
  int start = v2id[pi(0, X)];
  int goal = v2id[pi(n - 1, H[n - 1])];
  fill(d.begin(), d.end(), INF);
  d[start] = 0;
  vector<P> pq;
  pq.pb(pi(0, start));
  for (int i = 0; i < pq.size(); ++i) {
    P now = pq[i];
    int v = now.se;
    if (now.fi > d[v])
      continue;
    for (const auto &e : gg[v]) {
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        pq.pb(pi(d[e.to], e.to));
      }
    }
  }
  ll ans = d[goal];
  if (ans == INF)
    ans = -1;
  printf("%lld\n", ans);
  return 0;
}