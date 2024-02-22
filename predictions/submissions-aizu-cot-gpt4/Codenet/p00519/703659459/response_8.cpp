#include <vector>
#include <queue>
#include <utility>
#include <limits>
#include <iostream>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = numeric_limits<int>::max();
vector<int> pass[6000];
int n, k;
int c[6000];
int r[6000];
vector<bool> used;
priority_queue<pii, vector<pii>, greater<pii>> pq;

void dfs(int v, int u, int f, int end) {
  if (used[u])
    return;
  used[u] = true;
  pq.push(make_pair(c[v] + c[u], u));
  if (f >= end)
    return;
  for (int i = 0; i < pass[u].size(); i++) {
    dfs(v, pass[u][i], f + 1, end);
  }
}

int dijk(int s, int g) {
  vi d(n, INF);
  used = vector<bool>(n, false);
  d[s] = 0;
  pq.push(make_pair(0, s));
  while (!pq.empty()) {
    int v = pq.top().second;
    pq.pop();
    if (used[v])
      continue;
    used[v] = true;
    for (int i = 0; i < pass[v].size(); i++) {
      dfs(v, pass[v][i], 1, r[v]);
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