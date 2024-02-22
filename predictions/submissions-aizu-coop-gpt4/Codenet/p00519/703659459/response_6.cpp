#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

const int INF = 1e9+7;
const int MAXN = 6000;

vector<int> pass[MAXN];
int n, k;
int c[MAXN];
int r[MAXN];
int d[MAXN];
vector<bool> used(MAXN, false);
vector<bool> visited(MAXN, false);

void dfs(int v, int u, int f, int end) {
  if (visited[u])
    return;
  visited[u] = true;
  d[u] = min(d[u], d[v] + c[v]);
  if (f >= end)
    return;
  for(auto &i : pass[u]) {
    dfs(v, i, f + 1, end);
  }
}

int dijk(int s, int g) {
  fill(d, d+MAXN, INF);
  fill(used.begin(), used.end(), false);
  d[s] = 0;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, s});

  while (!pq.empty()) {
    int v = pq.top().second;
    pq.pop();
    if(used[v]) continue;
    used[v] = true;
    fill(visited.begin(), visited.end(), false);
    for(auto &i : pass[v]) {
      dfs(v, i, 1, r[v]);
      if(!used[i]) pq.push({d[i], i});
    }
  }
  return d[g];
}

int main() {
  cin >> n >> k;
  for(int i=0; i<n; i++) cin >> c[i] >> r[i];
  for(int i=0; i<k; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    pass[a].push_back(b);
    pass[b].push_back(a);
  }
  cout << dijk(0, n - 1) << endl;
}