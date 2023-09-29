#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

const int MAXN = 6000;
const int INF = 999999999;

vi pass[MAXN];
int n, k;
int c[MAXN];
int r[MAXN];
int d[MAXN];
bool used[MAXN];

void dfs(int v, int u, int f, int end, bool visited[MAXN]) {
  if (visited[u]) return;
  visited[u] = true;
  d[u] = min(d[u], d[v] + c[v]);
  if (f >= end) return;
  for (int i = 0; i < pass[u].size(); i++) {
    dfs(v, pass[u][i], f + 1, end, visited);
  }
}

int dijk(int s, int g) {
  for (int i = 0; i < n; i++) d[i] = INF;
  memset(used, false, sizeof(used));
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
  pq.push(make_pair(0, s));
  d[s] = 0;
  while (!pq.empty()) {
    int v = pq.top().second;
    pq.pop();
    if (used[v]) continue;
    used[v] = true;
    for (int i = 0; i < pass[v].size(); i++) {
      bool visited[MAXN] = {};
      dfs(v, pass[v][i], 1, r[v], visited);
    }
    for (int i = 0; i < pass[v].size(); i++) {
      int u = pass[v][i];
      if (d[u] > d[v] + c[v]) {
        d[u] = d[v] + c[v];
        pq.push(make_pair(d[u], u));
      }
    }
  }
  return d[g];
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> c[i] >> r[i];
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    pass[a].push_back(b);
    pass[b].push_back(a);
  }
  cout << dijk(0, n - 1) << endl;
  return 0;
}