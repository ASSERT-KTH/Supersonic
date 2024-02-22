#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int MAXN = 6000;
const int INF = numeric_limits<int>::max();

vector<int> pass[MAXN];
int n, k;
int c[MAXN];
int r[MAXN];
int d[MAXN];
bool used[MAXN];

void dfs(int v, int u, int f, int end, const vector<bool>& visited) {
  if (visited[u])
    return;
  visited[u] = true;
  d[u] = min(d[u], d[v] + c[v]);
  if (f >= end)
    return;
  for (int i : pass[u]) {
    dfs(v, i, f + 1, end, visited);
  }
}

int dijk(int s, int g) {
  for (int i = 0; i < MAXN; i++) d[i] = INF;
  for (int i = 0; i < MAXN; i++) used[i] = false;
  d[s] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push(make_pair(0, s));
  while (!pq.empty()) {
    int v = pq.top().second;
    pq.pop();
    if (used[v])
      continue;
    used[v] = true;
    for (int i : pass[v]) {
      vector<bool> visited(MAXN, false);
      dfs(v, i, 1, r[v], visited);
    }
  }
  return d[g];
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> c[i] >> r[i];
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    pass[a].push_back(b);
    pass[b].push_back(a);
  }
  cout << dijk(0, n - 1) << endl;
}