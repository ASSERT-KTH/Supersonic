#include <iostream>
#include <queue>
#include <vector>
#define INF (1 << 23)
using namespace std;

int main() {
  int N, M, s, t, u, v;
  cin >> N >> M >> s >> t;
  s--;
  t--;

  vector<vector<int>> G(N);
  for (int i = 0; i < M; i++) {
    cin >> u >> v;
    G[u - 1].push_back(v - 1);
    G[v - 1].push_back(u - 1);
  }

  vector<int> d1, d2;
  d1.reserve(N);
  d2.reserve(N);
  d1.assign(N, INF);
  d2.assign(N, INF);
  d1[s] = 0;
  d2[t] = 0;

  queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int node = que.front();
    que.pop();
    for (int i = 0; i < G[node].size(); i++) {
      if (d1[G[node][i]] == INF) {
        d1[G[node][i]] = d1[node] + 1;
        que.push(G[node][i]);
      }
    }
  }

  que.push(t);
  while (!que.empty()) {
    int node = que.front();
    que.pop();
    for (int i = 0; i < G[node].size(); i++) {
      if (d2[G[node][i]] == INF) {
        d2[G[node][i]] = d2[node] + 1;
        que.push(G[node][i]);
      }
    }
  }

  int shortest = d1[t];
  int r1_size = shortest - 1;
  vector<bool> r1(r1_size, false);
  vector<bool> r2(r1_size, false);

  for (int i = 0; i < N; i++) {
    if (d1[i] < shortest - 1) {
      r1[d1[i]] = true;
    }
  }

  for (int i = 0; i < N; i++) {
    if (d2[i] < shortest - 1) {
      r2[d2[i]] = true;
    }
  }

  long long ret = 0;
  for (int i = 0; i < r1_size; i++) {
    ret += r1[i] * r2[r1_size - i - 1];
  }

  cout << ret << endl;
  return 0;
}