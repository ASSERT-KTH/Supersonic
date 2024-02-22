#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <climits>
#include <cassert>
using namespace std;
using ll = long long;
#define rep(i, n) for (int(i) = 0; (i) < (int)(n); ++(i))
#define all(x) (x).begin(), (x).end()
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
unordered_map<pi, int> v2id;
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
    G[a].emplace_back(edge{b, t});
    G[b].emplace_back(edge{a, t});
  }
  // Rest of your code here...
}