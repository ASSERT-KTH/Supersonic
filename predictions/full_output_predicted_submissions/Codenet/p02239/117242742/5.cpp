#include <iostream>
#include <queue>
using namespace std;
int m[105][105], n, v[105], d[105];
void bfs(int s) {
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
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    d[i] = -1;
  for (int i = 0; i < n; i++) {
    int u, v, k;
    scanf("%d%d", &u, &k);
    for (int j = 0; j < k; j++) {
      scanf("%d", &v);
      m[u - 1][v - 1] = true;
    }
  }
  bfs(0);
  for (int i = 0; i < n; i++)
    printf("%d %d\n", i + 1, d[i]);
  return 0;
}
