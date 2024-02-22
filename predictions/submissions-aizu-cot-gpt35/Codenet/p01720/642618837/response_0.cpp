#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

int main() {
  size_t N, M, s, t, u, v;
  cin >> N >> M >> s >> t;
  s--;
  t--;

  vector<vector<int>> G(N);
  G.reserve(N);
  for (size_t i = 0; i < M; i++) {
    cin >> u >> v;
    G[u - 1].emplace_back(v - 1);
    G[v - 1].emplace_back(u - 1);
  }

  vector<int> d1(N, INT_MAX), d2(N, INT_MAX);
  d1[s] = 0;
  d2[t] = 0;

  queue<size_t> que;
  que.push(s);
  while (!que.empty()) {
    size_t node = que.front();
    que.pop();
    for (auto neighbor : G[node]) {
      if (d1[neighbor] == INT_MAX) {
        d1[neighbor] = d1[node] + 1;
        que.push(neighbor);
      }
    }
  }

  que.push(t);
  while (!que.empty()) {
    size_t node = que.front();
    que.pop();
    for (auto neighbor : G[node]) {
      if (d2[neighbor] == INT_MAX) {
        d2[neighbor] = d2[node] + 1;
        que.push(neighbor);
      }
    }
  }

  int shortest = d1[t];
  vector<int> r1(shortest - 1, 0), r2(shortest - 1, 0);
  r1.reserve(shortest - 1);
  r2.reserve(shortest - 1);

  for (size_t i = 0; i < N; i++) {
    if (d1[i] < shortest - 1) {
      r1[d1[i]]++;
    }
  }

  for (size_t i = 0; i < N; i++) {
    if (d2[i] < shortest - 1) {
      r2[d2[i]]++;
    }
  }

  long long ret = 0;
  for (size_t i = 0; i < shortest - 1; i++) {
    ret += 1LL * r1[i] * r2[shortest - i - 2];
  }

  cout << ret << endl;
  return 0;
}