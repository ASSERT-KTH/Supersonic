#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int(i) = 0; (i) < (int)(n); ++(i))
#define all(x) (x).begin(), (x).end()
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
vector<edge> G[V], gg[VV];
vector<int> height[V];
int n, m;
ll X;
int H[V];
vector<int> v2id;
int max_h[V] = {};
ll d[VV];
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
  v2id.pb(0);
  max_h[0] = X;
  height[0].pb(X);
  while (!que.empty()) {
    pi p = que.back();
    que.pop_back();
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
        if (v2id.size() <= ct) {
          v2id.pb(ct++);
        }
        if (v2id.size() <= ct) {
          v2id.pb(ct++);
        }
        int uu = v2id[ct - 2], vv = v2id[ct - 1];
        gg[uu].pb({vv, e.cost});
        max_h[e.to] = nh;
        que.pb(pi(max_h[e.to], e.to));
      }
    }
  }
  rep(i, n) for (const auto &e : G[i]) {
    if (H[i] < e.cost)
      continue;
    if (v2id.size() <= ct) {
      v2id.pb(ct++);
    }
    if (v2id.size() <= ct) {
      v2id.pb(ct++);
    }
    int uu = v2id[ct - 2];
    int vv = v2id[ct - 1];
    gg[uu].pb({vv, e.cost});
  }
  if (v2id.size() <= ct) {
    v2id.pb(ct++);
  }
  rep(i, n) {
    int S = height[i].size();
    auto itr = height[i].begin();
    rep(j, S - 1) {
      auto nx = itr;
      ++nx;
      int uu = v2id[*itr];
      int vv = v2id[*nx];
      int dist = *nx - *itr;
      gg[uu].pb({vv, dist});
      gg[vv].pb({uu, dist});
      itr = nx;
    }
  }
  int start = v2id[0];
  int goal = v2id[n - 1];
  fill(d, d + VV, INF);
  d[start] = 0;
  vector<P> pq;
  pq.pb(pi(0, start));
  while (!pq.empty()) {
    P now = pq.back();
    pq.pop_back();
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