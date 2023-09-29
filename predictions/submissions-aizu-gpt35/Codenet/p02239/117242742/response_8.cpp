#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
bool m[105][105];
int n, d[105];
void bfs(int s) {
  memset(d, -1, sizeof(d));
  d[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < n; i++) {
      if (m[u][i] && d[i] == -1) {
        d[i] = d[u] + 1;
        q.push(i);
      }
    }
  }
}
int main() {
  cin >> n;
  memset(m, 0, sizeof(m));
  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      int v;
      cin >> v;
      m[u - 1][v - 1] = true;
    }
  }
  bfs(0);
  for (int i = 0; i < n; i++)
    cout << i + 1 << ' ' << d[i] << endl;
  return 0;
}