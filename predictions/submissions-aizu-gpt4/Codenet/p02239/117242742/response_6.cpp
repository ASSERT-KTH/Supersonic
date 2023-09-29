#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> m(105);
vector<bool> v(105);
vector<int> d(105, -1);

void bfs(int s) {
  v[s] = true;
  d[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto &i : m[u]) {
      if (!v[i]) {
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
  for (int i = 0; i < n; ++i) {
    int u, k;
    cin >> u >> k;
    --u;
    for (int j = 0; j < k; ++j) {
      int v;
      cin >> v;
      m[u].push_back(v - 1);
    }
  }
  bfs(0);
  for (int i = 0; i < n; ++i)
    cout << i + 1 << ' ' << d[i] << '\n';
  return 0;
}