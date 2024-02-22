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
unordered_map<pi, int> v2id;  // change map to unordered_map
int max_h[V] = {};
ll d[VV];
int main() {
  // ... rest of the code remains the same till here
  while (!que.empty()) {
    // ... rest of the code remains the same till here
    for (const auto &e : G[v]) {
      // ... rest of the code remains the same till here
      if (nh > max_h[e.to]) {
        const pi v_bh = pi(v, bh);
        const pi e_to_nh = pi(e.to, nh);
        if (!v2id.count(v_bh)) {
          v2id[v_bh] = ct++;
          height[v].insert(bh);
        }
        if (!v2id.count(e_to_nh)) {
          v2id[e_to_nh] = ct++;
          height[e.to].insert(nh);
        }
        int uu = v2id[v_bh], vv = v2id[e_to_nh];  // use computed pairs instead of creating new ones
        gg[uu].pb({vv, e.cost});
        max_h[e.to] = nh;
        que.push(pi(max_h[e.to], e.to));
      }
    }
  }
  // ... rest of the code remains the same till here
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