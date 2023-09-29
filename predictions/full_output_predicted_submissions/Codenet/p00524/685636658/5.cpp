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
vector<int> height[V];
int n, m;
ll X;
int H[V];
map<pi, int> v2id;
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
  v2id[pi(0, X)] = 0;
  max_h[0] = X;
  height[0].insert(X);
  while (!que.empty()) {
    pi p = que.top();
    que.pop();
    int v = p.se, h = p.fi;
    if (h < max_h[v])
      continue;
    for (const auto &e : G[v]) {
 