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

  vector<int> G[N];
  for (int i = 0; i < M; i++) {
    cin >> u >> v;
    G[u - 1].push_back(v - 1);
    G[v - 1].push_back(u - 1);
  }

  int d1[N], d2[N];
  fill(d1, d1 + N, INF);
  fill(d2, d2 + N, INF);
  d1[s] = 0;
  d2[t] = 0;

  deque<int> que;
  que.push_back(s);
  while (!que.empty()) {
    int node = que.front();
    que.pop_front();
    for (int i = 0; i < G[node].size(); i++) {
      if (d1[G[node][i]] == INF) {
        d1[G[node][i]] = d1[node] + 1;
        que.push_back(G[node][i]);
      }
    }
  }

  que.push_back(t);
  while (!que.empty()) {
    int node = que.front();
    que.pop_front();
    for (int i = 0; i < G[node].size(); i++) {
      if (d2[G[node][i]] == INF) {
        d2[G[node][i]] = d2[node] + 1;
        que.push_back(G[node][i]);
      }
    }
  }

  int shortest = d1[t];
  int r1[shortest - 1] = {0};
  for (int i = 0; i < N; i++) {
    if (d1[i] < shortest - 1) {
      r1[d1[i]]++;
    }
  }

  int r2[shortest - 1] = {0};
  for (int i = 0; i < N; i++) {
    if (d2[i] < shortest - 1) {
      r2[d2[i]]++;
    }
  }

  long long ret = 0;
  for (int i = 0; i < shortest - 1; i++) {
    ret += 1LL * r1[i] * r2[shortest - i - 2];
  }

  cout << ret << endl;

  return 0;
}