#include <functional>
#include <iostream>
#include <queue>
#include <vector>
#pragma warning(disable : 4996)
#define INF (1 << 23)
using namespace std;
int main() {
  int N, M, s, t, u, v;
  scanf("%d %d %d %d", &N, &M, &s, &t);
  s--;
  t--;
  vector<vector<int>> G(N);
  for (int i = 0; i < M; i++) {
    scanf("%d %d", &u, &v);
    G[u - 1].push_back(v - 1);
  }
  vector<int> d1(N, INF);
  d1[s] = 0;
  vector<int> d2(N, INF);
  d2[t] = 0;
  queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int node = que.front();
    que.pop();
    int size = G[node].size();
    for (int i = 0; i < size; i++) {
      int neighbour = G[node][i];
      if (d1[neighbour] == INF) {
        d1[neighbour] = d1[node] + 1;
        que.push(neighbour);
      }
    }
  }
  que.push(t);
  while (!que.empty()) {
    int node = que.front();
    que.pop();
    int size = G[node].size();
    for (int i = 0; i < size; i++) {
      int neighbour = G[node][i];
      if (d2[neighbour] == INF) {
        d2[neighbour] = d2[node] + 1;
        que.push(neighbour);
      }
    }
  }
  int shortest = d1[t];
  vector<int> r1(shortest, 0);
  vector<int> r2(shortest, 0);
  r1[shortest - 1] = 1;
  r2[shortest - 1] = 1;
  for (int i = 0; i < N; i++) {
    if (d1[i] < shortest - 1) {
      r1[d1[i]]++;
    }
    if (d2[i] < shortest - 1) {
      r2[d2[i]]++;
    }
  }
  long long ret = 0;
  for (int i = 0; i < shortest - 1; i++) {
    ret += r1[i] * r2[shortest - i - 2];
  }
  cout << ret << '\n';
  return 0;
}