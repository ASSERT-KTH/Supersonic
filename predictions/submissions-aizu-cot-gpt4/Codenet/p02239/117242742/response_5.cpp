#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>>& m, int n, vector<int>& v, vector<int>& d, int s) {
  v[s] = true;
  d[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < n; i++) {
      if (m[u][i] && !v[i]) {
        d[i] = d[u] + 1;
        v[i] = true;
        q.push(i);
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> m(n, vector<int>(n, 0));
  vector<int> v(n, 0), d(n, -1);
  
  for (int i = 0; i < n; i++) {
    int u, v, k;
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      cin >> v;
      m[u - 1][v - 1] = true;
    }
  }
  bfs(m, n, v, d, 0);
  for (int i = 0; i < n; i++)
    cout << i + 1 << ' ' << d[i] << endl;
  return 0;
}