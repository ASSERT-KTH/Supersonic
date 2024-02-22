#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>
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
vector<vector<int>> height(V);
int n, m;
ll X;
int H[V];
vector<int> v2id(VV, -1);
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
  priority_queue<pi> que;
  que.push(pi(X, 0));
  v2id[0] = 0;
  max_h[0] = X;
  height[0].pb(X);
  while (!que.empty()) {
    pi p = que.top();
    que.pop();
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
        if (v2id[v * VV + bh] == -1) {
          v2id[v * VV + bh] = ct++;
          height[v].pb(bh);
        }
        if (v2id[e.to * VV + nh] == -1) {
          v2id[e.to * VV + nh] = ct++;
          height[e.to].pb(nh);
        }
        int uu = v2id[v * VV + bh], vv = v2id[e.to * VV + nh];
        gg[uu].pb({vv, e.cost});
        max_h[e.to] = nh;
        que.push(pi(max_h[e.to], e.to));
      }
    }
  }
  rep(i, n) for (const auto &e : G[i]) {
    if (H[i] < e.cost)
      continue;
    if (v2id[i * VV + e.cost] == -1) {
      v2id[i * VV + e.cost] = ct++;
      height[i].pb(e.cost);
    }
    if (v2id[e.to * VV + 0] == -1) {
      v2id[e.to * VV + 0] = ct++;
      height[e.to].pb(0);
    }
    int uu = v2id[i * VV + e.cost];
    int vv = v2id[e.to * VV + 0];
    gg[uu].pb({vv, e.cost});
  }
  if (v2id[(n - 1) * VV + H[n - 1]] == -1) {
    v2id[(n - 1) * VV + H[n - 1]] = ct++;
    height[n - 1].pb(H[n - 1]);
  }
  rep(i, n) {
    int S = height[i].size();
    for (int j = 0; j < S - 1; ++j) {
      int uu = v2id[i * VV + height[i][j]];
      int vv = v2id[i * VV + height[i][j+1]];
      int dist = height[i][j+1] - height[i][j];
      gg[uu].pb({vv, dist});
      gg[vv].pb({uu, dist});
    }
  }
  int start = v2id[0 * VV + X];
  int goal = v2id[(n - 1) * VV + H[n - 1]];
  fill(d, d + VV, INF);
  d[start] = 0;
  priority_queue<P, vector<P>, greater<P>> pq;
  pq.push(pi(0, start));
  while (!pq.empty()) {
    P now = pq.top();
    pq.pop();
    int v = now.se;
    if (now.fi > d[v])
      continue;
    for (const auto &e : gg[v]) {
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        pq.push(pi(d[e.to], e.to));
      }
    }
  }
  ll ans = d[goal];
  if (ans == INF)
    ans = -1;
  printf("%lld\n", ans);
  return 0;
}