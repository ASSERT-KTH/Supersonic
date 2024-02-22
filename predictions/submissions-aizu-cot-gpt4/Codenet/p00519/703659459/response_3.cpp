#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 999999999;
vector<vector<int>> pass(6000);
int n, k;
int c[6000];
int r[6000];
int d[6000];
bool used[6000];
bool visited[6000];

void dfs(int v, int u, int f, int end) {
  if (visited[u])
    return;
  visited[u] = true;
  d[u] = min(d[u], d[v] + c[v]);
  if (f >= end)
    return;
  for (int i = 0; i < pass[u].size(); i++) {
    dfs(v, pass[u][i], f + 1, end);
  }
}

int dijk(int s, int g) {
  for (int i = 0; i < 6000; i++) {
    d[i] = INF;
    used[i] = false;
  }
  d[s] = 0;
  for (int i = 0; i < n; i++) {
    int v = -1;
    for (int u = 0; u < n; u++) {
      if (!used[u] && (v == -1 || d[u] < d[v]))
        v = u;
    }
    if (v == -1)
      break;
    used[v] = true;
    for (int j = 0; j < 6000; j++) {
      visited[j] = false;
    }
    for (int j = 0; j < pass[v].size(); j++) {
      dfs(v, pass[v][j], 1, r[v]);
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
}