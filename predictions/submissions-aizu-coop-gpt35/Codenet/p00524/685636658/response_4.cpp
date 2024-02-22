#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int(i) = 0; (i) < (int)(n); ++(i))
using pi = pair<int, int>;
struct edge {
  int to;
  int cost;
};
const int V = 100000;
const int VV = 1000000;
const int INF = INT_MAX / 3;
vector<edge> G[V], gg[VV];
int n, m;
int X;
int H[V];
unordered_map<pi, int> v2id;
int max_h[V] = {};
int d[VV];
int main() {
  scanf(" %d %d %d", &n, &m, &X);
  rep(i, n) scanf(" %d", &H[i]);
  rep(i, m) {
    int a, b, t;
    scanf(" %d %d %d", &a, &b, &t);
    --a;
    --b;
    G[a].push_back({b, t});
    G[b].push_back({a, t});
  }
  int ct = 1;
  priority_queue<pi> que;
  que.push(pi(X, 0));
  v2id[pi(0, X)] = 0;
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
          v2id[pi(v, bh)] = ct++;
        }
        if (!v2id.count(pi(e.to, nh))) {
          v2id[pi(e.to, nh)] = ct++;
        }
        int uu = v2id[pi(v, bh)], vv = v2id[pi(e.to, nh)];
        gg[uu].push_back({vv, e.cost});
        max_h[e.to] = nh;
        que.push(pi(max_h[e.to], e.to));
      }
    }
  }
  rep(i, n) {
    int S = G[i].size();
    rep(j, S) {
      const auto &e = G[i][j];
      if (H[i] < e.cost)
        continue;
      if (!v2id.count(pi(i, e.cost))) {
        v2id[pi(i, e.cost)] = ct++;
      }
      if (!v2id.count(pi(e.to, 0))) {
        v2id[pi(e.to, 0)] = ct++;
      }
      int uu = v2id[pi(i, e.cost)];
      int vv = v2id[pi(e.to, 0)];
      gg[uu].push_back({vv, e.cost});
    }
  }
  if (!v2id.count(pi(n - 1, H[n - 1]))) {
    v2id[pi(n - 1, H[n - 1])] = ct++;
  }
  int start = v2id[pi(0, X)];
  int goal = v2id[pi(n - 1, H[n - 1])];
  memset(d, INF, sizeof(d));
  d[start] = 0;
  priority_queue<pi, vector<pi>, greater<pi>> pq;
  pq.push(pi(0, start));
  while (!pq.empty()) {
    pi now = pq.top();
    pq.pop();
    int v = now.second;
    if (now.first > d[v])
      continue;
    for (const auto &e : gg[v]) {
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        pq.push(pi(d[e.to], e.to));
      }
    }
  }
  int ans = d[goal];
  if (ans == INF)
    ans = -1;
  printf("%d\n", ans);
  return 0;
}