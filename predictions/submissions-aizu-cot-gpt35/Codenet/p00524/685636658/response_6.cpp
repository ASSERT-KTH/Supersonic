#include <cstdio>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cassert>
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

vector<edge> G[V];
vector<edge> gg[VV];
vector<int> height[V];
int n, m;
ll X;
int H[V];
unordered_map<pi, int> v2id;
int max_h[V] = {};
ll d[VV];

int main() {
  scanf(" %d %d %lld", &n, &m, &X);
  for (int i = 0; i < n; ++i) {
    scanf(" %d", &H[i]);
  }

  for (int i = 0; i < m; ++i) {
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
  height[0].push_back(X);

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
        v2id[pi(v, bh)] = ct;
        height[v].push_back(bh);
        v2id[pi(e.to, nh)] = ct + 1;
        height[e.to].push_back(nh);
        int uu = ct, vv = ct + 1;
        gg[uu].push_back({vv, e.cost});
        max_h[e.to] = nh;
        que.push(pi(max_h[e.to], e.to));
        ct += 2;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (const auto &e : G[i]) {
      if (H[i] < e.cost)
        continue;
      v2id[pi(i, e.cost)] = ct;
      height[i].push_back(e.cost);
      v2id[pi(e.to, 0)] = ct + 1;
      height[e.to].push_back(0);
      int uu = ct, vv = ct + 1;
      gg[uu].push_back({vv, e.cost});
      ct += 2;
    }
  }

  if (!v2id.count(pi(n - 1, H[n - 1]))) {
    v2id[pi(n - 1, H[n - 1])] = ct;
    height[n - 1].push_back(H[n - 1]);
  }

  for (int i = 0; i < n; ++i) {
    int S = height[i].size();
    for (int j = 0; j < S - 1; ++j) {
      int uu = v2id[pi(i, height[i][j])];
      int vv = v2id[pi(i, height[i][j + 1])];
      int dist = height[i][j + 1] - height[i][j];
      gg[uu].push_back({vv, dist});
      gg[vv].push_back({uu, dist});
    }
  }

  int start = v2id[pi(0, X)];
  int goal = v2id[pi(n - 1, H[n - 1])];
  for (int i = 0; i < VV; ++i) {
    d[i] = INF;
  }
  d[start] = 0;
  priority_queue<P, vector<P>, greater<P>> pq;
  pq.push(pi(0, start));

  while (!pq.empty()) {
    P now = pq.top();
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

  ll ans = d[goal];
  if (ans == INF)
    ans = -1;
  printf("%lld\n", ans);
  return 0;
}