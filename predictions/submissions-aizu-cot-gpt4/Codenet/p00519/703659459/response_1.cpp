#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define MAX_SIZE 6000

using namespace std;

int pass[MAX_SIZE][MAX_SIZE];
int n, k;
int c[MAX_SIZE];
int r[MAX_SIZE];
int d[MAX_SIZE];
bool used[MAX_SIZE];
const int INF = INT_MAX;

void dfs(int v, int u, int f, int end, bool visited[MAX_SIZE]) {
  if (visited[u])
    return;
  visited[u] = true;
  d[u] = min(d[u], d[v] + c[v]);
  if (f >= end)
    return;
  int size = pass[u].size();
  for (int i = 0; i < size; i++) { dfs(v, pass[u][i], f + 1, end, visited); }
}

int dijk(int s, int g) {
  for (int i = 0; i < MAX_SIZE; i++) {
    d[i] = INF;
    used[i] = false;
  }
  d[s] = 0;
  while (1) {
    int v = -1;
    for (int u = 0; u < n; u++) {
      if (!used[u] && (v == -1 || d[u] < d[v]))
        v = u;
    }
    if (v == -1)
      break;
    used[v] = true;
    bool visited[MAX_SIZE] = {};
    int size = pass[v].size();
    for (int i = 0; i < size; i++) { dfs(v, pass[v][i], 1, r[v], visited); }
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
    pass[a][i] = b;
    pass[b][i] = a;
  }
  cout << dijk(0, n - 1) << endl;
}