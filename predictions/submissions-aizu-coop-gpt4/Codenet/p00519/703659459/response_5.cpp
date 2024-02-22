#include "bits/stdc++.h"
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define INF 999999999
vector<int> pass[6000];
int n, k;
int c[6000];
int r[6000];
int d[6000];
bool used[6000];
void dfs(int v, int u, int f, int end) {
  stack<pair<int, int>> stack;
  stack.push(make_pair(u, f));
  while (!stack.empty()) {
    tie(u, f) = stack.top();
    stack.pop();
    if (used[u])
      continue;
    used[u] = true;
    d[u] = min(d[u], d[v] + c[v]);
    if (f < end)
      for (int i : pass[u])
        if (!used[i])
          stack.push(make_pair(i, f + 1));
  }
}
int dijk(int s, int g) {
  priority_queue<pii, vector<pii>, greater<pii>> queue;
  fill(d, d + 6000, INF);
  fill(used, used + 6000, false);
  d[s] = 0;
  queue.push(make_pair(0, s));
  while (!queue.empty()) {
    int v = queue.top().second;
    queue.pop();
    if (used[v])
      continue;
    used[v] = true;
    for (int i : pass[v]) {
      if (!used[i]) {
        dfs(v, i, 1, r[v]);
        if (d[i] != INF)
          queue.push(make_pair(d[i], i));
      }
    }
  }
  return d[g];
}
int main() {
  cin >> n >> k;
  rep(i, n) cin >> c[i] >> r[i];
  rep(i, k) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    pass[a].pb(b);
    pass[b].pb(a);
  }
  cout << dijk(0, n - 1) << endl;
}