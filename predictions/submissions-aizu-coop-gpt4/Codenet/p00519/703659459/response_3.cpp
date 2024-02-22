#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define INF INT_MAX
vector<int> pass[6000];
int n, k;
int c[6000];
int r[6000];
int d[6000];
bool used[6000];

void dfs(int v) {
  vector<pii> stack; // Stack for DFS, contains pair of node and remaining depth
  stack.push_back(pii(v, r[v]));
  while(!stack.empty()) {
    pii top = stack.back();
    stack.pop_back();
    int node = top.first;
    int depth = top.second;
    if (used[node])
      continue;
    used[node] = true;
    d[node] = min(d[node], d[v] + c[v]);
    if (depth > 0)
      for (int u : pass[node])
        stack.push_back(pii(u, depth - 1));
  }
}

int dijk(int s, int g) {
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push(pii(0, s));
  while (!pq.empty()) {
    int v = pq.top().second; pq.pop();
    if (used[v])
      continue;
    used[v] = true;
    for (int u : pass[v]) {
      if (!used[u]) {
        dfs(u);
        if (d[u] < INF)
          pq.push(pii(d[u], u));
      }
    }
  }
  return d[g];
}

int main() {
  cin >> n >> k;
  fill(d, d + 6000, INF);
  rep(i, n) cin >> c[i] >> r[i];
  rep(i, k) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    pass[a].pb(b);
    pass[b].pb(a);
  }
  d[0] = 0;
  cout << dijk(0, n - 1) << endl;
}