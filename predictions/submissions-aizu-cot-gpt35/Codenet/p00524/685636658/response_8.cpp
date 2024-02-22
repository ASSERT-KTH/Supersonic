#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
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

const ll INF = LLONG_MAX / 3;

int main() {
  int n, m;
  ll X;
  cin >> n >> m >> X;

  vector<int> H(n);
  for (int i = 0; i < n; ++i) {
    cin >> H[i];
  }

  vector<vector<pair<int, ll>>> G(n);
  for (int i = 0; i < m; ++i) {
    int a, b, t;
    cin >> a >> b >> t;
    --a;
    --b;
    G[a].emplace_back(b, t);
    G[b].emplace_back(a, t);
  }

  int ct = 1;
  priority_queue<pi> que;
  que.emplace(X, 0);
  
  unordered_map<pi, int> v2id;
  v2id.emplace(pi(0, X), 0);
  
  vector<int> max_h(n, 0);
  max_h[0] = X;

  vector<set<int>> height(n);
  height[0].insert(X);

  while (!que.empty()) {
    pi p = que.top();
    que.pop();
    int v = p.second, h = p.first;

    if (h < max_h[v])
      continue;

    for (const auto& e : G[v]) {
      int bh = h;
      int nh = h - e.cost;

      if (nh < 0)
        continue;

      if (nh > H[e.to]) {
        bh = H[e.to] + e.cost;
        nh = H[e.to];
      }

      if (nh > max_h[e.to]) {
        auto it1 = v2id.emplace(pi(v, bh), ct++);
        height[v].insert(bh);

        auto it2 = v2id.emplace(pi(e.to, nh), ct++);
        height[e.to].insert(nh);

        int uu = it1.first->second, vv = it2.first->second;
        G[uu].emplace_back(vv, e.cost);
        max_h[e.to] = nh;
        que.emplace(max_h[e.to], e.to);
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (const auto& e : G[i]) {
      if (H[i] < e.cost)
        continue;

      auto it1 = v2id.emplace(pi(i, e.cost), ct++);
      height[i].insert(e.cost);

      auto it2 = v2id.emplace(pi(e.to, 0), ct++);
      height[e.to].insert(0);

      int uu = it1.first->second;
      int vv = it2.first->second;

      G[uu].emplace_back(vv, e.cost);
    }
  }

  if (!v2id.count(pi(n - 1, H[n - 1]))) {
    v2id.emplace(pi(n - 1, H[n - 1]), ct++);
    height[n - 1].insert(H[n - 1]);
  }

  for (int i = 0; i < n; ++i) {
    int S = height[i].size();
    auto itr = height[i].begin();

    for (int j = 0; j < S - 1; ++j) {
      auto nx = itr;
      ++nx;
      int uu = v2id[pi(i, *itr)];
      int vv = v2id[pi(i, *nx)];
      int dist = *nx - *itr;
      G[uu].emplace_back(vv, dist);
      G[vv].emplace_back(uu, dist);
      itr = nx;
    }
  }

  int start = v2id[pi(0, X)];
  int goal = v2id[pi(n - 1, H[n - 1])];

  int VV = ct;
  vector<ll> d(VV, INF);
  d[start] = 0;

  priority_queue<P, vector<P>, greater<P>> pq;
  pq.emplace(0, start);

  while (!pq.empty()) {
    P now = pq.top();
    pq.pop();

    int v = now.second;

    if (now.first > d[v])
      continue;

    for (const auto& e : G[v]) {
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        pq.emplace(d[e.to], e.to);
      }
    }
  }

  ll ans = d[goal];
  if (ans == INF)
    ans = -1;

  cout << ans << endl;

  return 0;
}