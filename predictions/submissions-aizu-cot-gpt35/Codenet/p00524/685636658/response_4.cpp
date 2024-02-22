#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>

using namespace std;

using ll = long long;

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
unordered_map<pair<int, int>, int> v2id;
int max_h[V] = {};
ll d[VV];

int main() {
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
  que.emplace(X, 0);
  v2id[{0, X}] = 0;
  max_h[0] = X;
  height[0].push_back(X);
  while (!que.empty()) {
    pair<int, int> p = que.top();
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
        if (v2id.find({v, bh}) == v2id.end()) {
          v2id[{v, bh}] = ct++;
          height[v].push_back(bh);
        }
        if (v2id.find({e.to, nh}) == v2id.end()) {
          v2id[{e.to, nh}] = ct++;
          height[e.to].push_back(nh);
        }
        int uu = v2id[{v, bh}], vv = v2id[{e.to, nh}];
        gg[uu].emplace_back(vv, e.cost);
        max_h[e.to] = nh;
        que.emplace(max_h[e.to], e.to);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (const auto &e : G[i]) {
      if (H[i] < e.cost)
        continue;
      if (v2id.find({i, e.cost}) == v2id.end()) {
        v2id[{i, e.cost}] = ct++;
        height[i].push_back(e.cost);
      }
      if (v2id.find({e.to, 0}) == v2id.end()) {
        v2id[{e.to, 0}] = ct++;
        height[e.to].push_back(0);
      }
      int uu = v2id[{i, e.cost}];
      int vv = v2id[{e.to, 0}];
      gg[uu].emplace_back(vv, e.cost);
    }
  }
  if (v2id.find({n - 1, H[n - 1]}) == v2id.end()) {
    v2id[{n - 1, H[n - 1]}] = ct++;
    height[n - 1].push_back(H[n - 1]);
  }
  for (int i = 0; i < n; ++i) {
    int S = height[i].size();
    for (int j = 0; j < S - 1; ++j) {
      int uu = v2id[{i, height[i][j]}];
      int vv = v2id[{i, height[i][j + 1]}];
      int dist = height[i][j + 1] - height[i][j];
      gg[uu].emplace_back(vv, dist);
      gg[vv].emplace_back(uu, dist);
    }
  }
  int start = v2id[{0, X}];
  int goal = v2id[{n - 1, H[n - 1]}];
  fill(d, d + VV, INF);
  d[start] = 0;
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  pq.emplace(0, start);
  while (!pq.empty()) {
    pair<ll, int> now = pq.top();
    pq.pop();
    int v = now.second;
    if (now.first > d[v])
      continue;
    for (const auto &e : gg[v]) {
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