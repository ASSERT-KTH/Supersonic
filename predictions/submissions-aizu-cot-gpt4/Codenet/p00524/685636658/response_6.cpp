#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <climits>

using namespace std;
using ll = long long;
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
bool height[V][V];
int n, m;
ll X;
int H[V];
int v2id[V][V];
int max_h[V] = {};
ll d[VV];

int main() {
  scanf(" %d %d %lld", &n, &m, &X);
  for (int i = 0; i < n; ++i) scanf(" %d", &H[i]);
  for (int i = 0; i < m; ++i) {
    int a, b, t;
    scanf(" %d %d %d", &a, &b, &t);
    --a; --b;
    G[a].push_back({b, t});
    G[b].push_back({a, t});
  }
  int ct = 1;
  priority_queue<pi> que;
  que.push(pi(X, 0));
  v2id[0][X] = 0;
  max_h[0] = X;
  height[0][X] = true;
  while (!que.empty()) {
    pi p = que.top();
    que.pop();
    int v = p.second, h = p.first;
    if (h < max_h[v]) continue;
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
        if (!v2id[v][bh]) {
          v2id[v][bh] = ct++;
          height[v][bh] = true;
        }
        if (!v2id[e.to][nh]) {
          v2id[e.to][nh] = ct++;
          height[e.to][nh] = true;
        }
        int uu = v2id[v][bh], vv = v2id[e.to][nh];
        gg[uu].push_back({vv, e.cost});
        max_h[e.to] = nh;
        que.push(pi(max_h[e.to], e.to));
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (const auto &e : G[i]) {
      if (H[i] < e.cost)
        continue;
      if (!v2id[i][e.cost]) {
        v2id[i][e.cost] = ct++;
        height[i][e.cost] = true;
      }
      if (!v2id[e.to][0]) {
        v2id[e.to][0] = ct++;
        height[e.to][0] = true;
      }
      int uu = v2id[i][e.cost];
      int vv = v2id[e.to][0];
      gg[uu].push_back({vv, e.cost});
    }
  }
  if (!v2id[n - 1][H[n - 1]]) {
    v2id[n - 1][H[n - 1]] = ct++;
    height[n - 1][H[n - 1]] = true;
  }
  for (int i = 0; i < n; ++i) {
    int S = count(height[i], height[i] + V, true);
    auto itr = find(height[i], height[i] + V, true);
    while (S-- > 1) {
      auto nx = find(itr + 1, height[i] + V, true);
      int uu = v2id[i][*itr];
      int vv = v2id[i][*nx];
      int dist = *nx - *itr;
      gg[uu].push_back({vv, dist});
      gg[vv].push_back({uu, dist});
      itr = nx;
    }
  }
  int start = v2id[0][X];
  int goal = v2id[n - 1][H[n - 1]];
  fill(d, d + VV, INF);
  d[start] = 0;
  priority_queue<P, vector<P>, greater<P>> pq;
  pq.push(P(0, start));
  while (!pq.empty()) {
    P now = pq.top();
    pq.pop();
    int v = now.second;
    if (now.first > d[v])
      continue;
    for (const auto &e : gg[v]) {
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        pq.push(P(d[e.to], e.to));
      }
    }
  }
  ll ans = d[goal];
  if (ans == INF)
    ans = -1;
  printf("%lld\n", ans);
  return 0;
}