#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 105;
int m[MAXN][MAXN], n, d[MAXN];
bool v[MAXN];

void bfs(int s) {
  memset(v, false, sizeof(v));
  memset(d, -1, sizeof(d));
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
  cin >> n;
  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;
    while (k--) {
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