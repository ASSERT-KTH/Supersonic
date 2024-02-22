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
set<int> height[V];
int n, m;
ll X;
int H[V];
unordered_map<pi, int> v2id;  // Changed from map to unordered_map
int max_h[V] = {};
ll d[VV];
int main() {
  // Snip...
  for (const auto &e : G[v]) {  // Changed from auto to auto&
    // Snip...
    auto it = v2id.find(pi(v, bh));
    if (it == v2id.end()) {
      it = v2id.insert(pi(v, bh), ct++).first;
      height[v].insert(bh);
    }
    auto it2 = v2id.find(pi(e.to, nh));
    if (it2 == v2id.end()) {
      it2 = v2id.insert(pi(e.to, nh), ct++).first;
      height[e.to].insert(nh);
    }
    // Snip...
  }
  // Snip...
  int start = v2id[pi(0, X)];
  int goal = v2id[pi(n - 1, H[n - 1])];
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
    for (const auto &e : gg[v]) {  // Changed from auto to auto&
      // Snip...
    }
  }
  // Snip...
  return 0;
}