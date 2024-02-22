#include <iostream>
#include <queue>
#include <vector>
#define INF (1 << 23)

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int N, M, s, t, u, v;
  cin >> N >> M >> s >> t;
  s--; t--;
  
  vector<vector<int>> G(N);
  
  for (int i = 0; i < M; i++) {
    cin >> u >> v;
    G[u - 1].push_back(v - 1);
    G[v - 1].push_back(u - 1);
  }
  
  vector<int> d1(N, INF), d2(N, INF), r1(N, 0), r2(N, 0);
  d1[s] = d2[t] = 0;
  
  queue<int> que;
  que.push(s);
  
  while (!que.empty()) {
    auto node = que.front();
    que.pop();
    for (auto neighbor : G[node]) {
      if (d1[neighbor] == INF) {
        d1[neighbor] = d1[node] + 1;
        r1[d1[neighbor]]++;
        que.push(neighbor);
      }
    }
  }
  
  que.push(t);
  
  while (!que.empty()) {
    auto node = que.front();
    que.pop();
    for (auto neighbor : G[node]) {
      if (d2[neighbor] == INF) {
        d2[neighbor] = d2[node] + 1;
        r2[d2[neighbor]]++;
        que.push(neighbor);
      }
    }
  }
  
  int shortest = d1[t];
  long long ret = 0;
  
  for (int i = 0; i < shortest - 1; i++) {
    ret += 1LL * r1[i] * r2[shortest - i - 2];
  }
  
  cout << ret << '\n';
  
  return 0;
}