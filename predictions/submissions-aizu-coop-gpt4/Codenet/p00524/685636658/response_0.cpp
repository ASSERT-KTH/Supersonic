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
vector<vector<edge>> G(V), gg(VV);
vector<set<int>> height(V);
int n, m;
ll X;
vector<int> H(V);
unordered_map<pi, int> v2id;
vector<int> max_h(V);
vector<ll> d(VV);
// other code here...