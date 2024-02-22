#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <cassert>

using namespace std;

using ll = long long;

const int V = 100000;
const int VV = 1000000;
const ll INF = LLONG_MAX / 3;

struct edge {
  int to;
  ll cost;
};

vector<edge> G[V];
vector<edge> gg[VV];
unordered_set<int> height[V];
int n, m;
ll X;
int H[V];
unordered_map<pair<int, int>, int> v2id;
int max_h[V] = {};
ll d[VV];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> m >> X;
  for (int i = 0; i < n; ++i) {
    cin >> H[i];
  }
  for (int i = 0; i < m; ++i) {
    int a, b, t;
    cin >> a >> b >> t;
    --a;
    --b;
    G[a].push_back({b, t});
    G[b].push_back({a, t});
  }
  
  int ct = 1;
  priority_queue<pair<int, int>> que;
  que.push({X, 0});
  v2id[{0, X}] = 0;
  max_h[0] = X;
  height[0].insert(X);
  
  while (!que.empty()) {
    auto p = que.top();
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
        if (v2id.count({v, bh}) == 0) {
          v2id[{v, bh}] = ct++;
          height[v].insert(bh);
        }
        if (v2id.count({e.to, nh}) == 0) {
          v2id[{e.to, nh}] = ct++;
          height[e.to].insert(nh);
        }
        int uu = v2id[{v, bh}], vv = v2id[{e.to, nh}];
        gg[uu].push_back({vv, e.cost});
        max_h[e.to] = nh;
        que.push({max_h[e.to], e.to});
      }
    }
  }
  
  for (int i = 0; i < n; ++i) {
    for (const auto &e : G[i]) {
      if (H[i] < e.cost)
        continue;
      if (v2id.count({i, e.cost}) == 0) {
        v2id[{i, e.cost}] = ct++;
        height[i].insert(e.cost);
      }
      if (v2id.count({e.to, 0}) == 0) {
        v2id[{e.to, 0}] = ct++;
        height[e.to].insert(0);
      }
      int uu = v2id[{i, e.cost}];
      int vv = v2id[{e.to, 0}];
      gg[uu].push_back({vv, e.cost});
    }
  }
  
  if (v2id.count({n - 1, H[n - 1]}) == 0) {
    v2id[{n - 1, H[n - 1]}] = ct++;
    height[n - 1].insert(H[n - 1]);
  }
  
  for (int i = 0; i < n; ++i) {
    int S = height[i].size();
    auto itr = height[i].begin();
    for (int j = 0; j < S - 1; ++j) {
      auto nx = itr;
      ++nx;
      assert(v2id.count({i, *itr}) != 0);
      assert(v2id.count({i, *nx}) != 0);
      int uu = v2id[{i, *itr}];
      int vv = v2id[{i, *nx}];
      int dist = *nx - *itr;
      gg[uu].push_back({vv, dist});
      gg[vv].push_back({uu, dist});
      itr = nx;
    }
  }
  
  int start = v2id[{0, X}];
  int goal = v2id[{n - 1, H[n - 1]}];
  fill(d, d + VV, INF);
  d[start] = 0;
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  pq.push({0, start});
  
  while (!pq.empty()) {
    auto now = pq.top();
    pq.pop();
    int v = now.second;
    if (now.first > d[v])
      continue;
    for (const auto &e : gg[v]) {
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        pq.push({d[e.to], e.to});
      }
    }
  }
  
  ll ans = d[goal];
  if (ans == INF)
    ans = -1;
  cout << ans << '\n';
  
  return 0;
}