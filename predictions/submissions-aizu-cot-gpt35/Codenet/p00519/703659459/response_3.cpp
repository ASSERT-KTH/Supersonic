#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

const int INF = numeric_limits<int>::max();

vector<int> pass[6000];
int n, k;
int c[6000];
int r[6000];
int d[6000];
bool used[6000];

void dfs(int v, int u, int f, int end, const bool visited[6000]) {
  if (visited[u])
    return;
  visited[u] = true;
  d[u] = min(d[u], d[v] + c[v]);
  if (f >= end)
    return;
  for (int i = 0; i < pass[u].size(); i++) {
    dfs(v, pass[u][i], f + 1, end, visited);
  }
}

int dijk(int s, int g) {
  for (int i = 0; i < 6000; i++)
    d[i] = INF;

  for (int i = 0; i < 6000; i++)
    used[i] = false;

  d[s] = 0;

  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push(make_pair(0, s));

  while (!pq.empty()) {
    int v = pq.top().second;
    pq.pop();

    if (used[v])
      continue;

    used[v] = true;

    for (int i = 0; i < pass[v].size(); i++) {
      bool visited[6000] = {};
      dfs(v, pass[v][i], 1, r[v], visited);
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

  return 0;
}