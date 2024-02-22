#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
#include <utility>
#include <climits>

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using P = pair<ll, int>;

struct edge {
  int to;
  ll cost;
};

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;  
    }
};

const int V = 100000;
const int VV = 1000000;
const ll INF = LLONG_MAX / 3;
vector<edge> G[V], gg[VV];
vector<set<int>> height(V);
int n, m;
ll X;
int H[V];
unordered_map<pi, int, pair_hash> v2id;
int max_h[V] = {};
ll d[VV];

int main() {
  // ...
  priority_queue<pi, vector<pi>, greater<pi>> que;
  // ...
  unordered_map<pi, int, pair_hash> v2id;
  // ...
  for(int i = 0; i < n; ++i) {
    // ...
  }
  // ...
  if (ans != INF)
    printf("%lld\n", ans);
  return 0;
}