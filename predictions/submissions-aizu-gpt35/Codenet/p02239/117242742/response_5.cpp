#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 105;
vector<int> m[MAXN];
int n, d[MAXN];

void bfs(int s) {
  fill_n(d, n, -1);
  d[s] = 0;
  queue<int> q{{s}};
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : m[u]) {
      if (d[v] == -1) {
        d[v] = d[u] + 1;
        q.emplace(v);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;
    m[u - 1].resize(k);
    for (int j = 0; j < k; j++) {
      cin >> m[u - 1][j];
      m[u - 1][j]--;
    }
  }
  bfs(0);
  for (int i = 0; i < n; i++)
    cout << i + 1 << ' ' << d[i] << '\n';
  return 0;
}