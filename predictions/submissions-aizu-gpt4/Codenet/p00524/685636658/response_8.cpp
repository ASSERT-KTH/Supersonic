#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int(i) = 0; (i) < (int)(n); ++(i))
using pi = pair<int, int>;
using P = pair<ll, int>;
struct edge {
  int to;
  ll cost;
};
const int V = 100000;
const ll INF = LLONG_MAX / 3;
vector<edge> G[V];
int n, m;
ll X;
int H[V];
map<pi, int> v2id;
int max_h[V] = {};
ll d[V];
int main() {
  scanf(" %d %d %lld", &n, &m, &X);
  rep(i, n) scanf(" %d", &H[i]);
  rep(i, m) {
    int a, b, t;
    scanf(" %d %d %d", &a, &b, &t);
    --a;
    --b;
    G[a].push_back({b, t});
    G[b].push_back({a, t});
  }
  priority_queue<pi> que;
  que.push(pi(X, 0));
  max_h[0] = X;
  while (!que.empty()) {
    pi p = que.top();
    que.pop();
    int v = p.second, h = p.first;
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
        if (!v2id.count(pi(v, bh))) {
          v2id[pi(v, bh)] = 1;
        }
        if (!v2id.count(pi(e.to, nh))) {
          v2id[pi(e.to, nh)] = 1;
        }
        max_h[e.to] = nh;
        que.push(pi(max_h[e.to], e.to));
      }
    }
  }
  int start = v2id[pi(0, X)];
  int goal = v2id[pi(n - 1, H[n - 1])];
  fill(d, d + V, INF);
  d[start] = 0;
  priority_queue<P, vector<P>, greater<P>> pq;
  pq.push(pi(0, start));
  while (!pq.empty()) {
    P now = pq.top();
    pq.pop();
    int v = now.second;
    if (now.first > d[v])
      continue;
    for (const auto &e : G[v]) {
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