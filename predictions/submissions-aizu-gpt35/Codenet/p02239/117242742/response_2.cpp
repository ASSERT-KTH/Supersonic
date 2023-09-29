#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 105;
vector<int> m[MAX_N];
int n, d[MAX_N];

void bfs(int s) {
  d[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < m[u].size(); i++) {
      int v = m[u][i];
      if (d[v] == -1) {
        d[v] = d[u] + 1;
        q.push(v);
      }
    }
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    d[i] = -1;
  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      int v;
      cin >> v;
      m[u - 1].push_back(v - 1);
    }
  }
  bfs(0);
  for (int i = 0; i < n; i++)
    cout << i + 1 << ' ' << d[i] << endl;
  return 0;
}