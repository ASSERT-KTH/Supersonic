#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 105;
vector<vector<int>> m(N);
int n, v[N], d[N];
void bfs(int s) {
  fill(v, v + N, 0);
  fill(d, d + N, -1);
  v[s] = 1;
  d[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto i : m[u]) {
      if (!v[i]) {
        d[i] = d[u] + 1;
        v[i] = 1;
        q.push(i);
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;
    u--;
    for (int j = 0; j < k; j++) {
      int v;
      cin >> v;
      v--;
      m[u].push_back(v);
    }
  }
  bfs(0);
  for (int i = 0; i < n; i++)
    cout << i + 1 << ' ' << d[i] << '\n';
  return 0;
}