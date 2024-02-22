#include <iostream>
#include <vector>
#include <deque>
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
  
  vector<int> d1(N, N + 1);
  d1[s] = 0;
  vector<int> d2(N, N + 1);
  d2[t] = 0;
  
  deque<int> que;
  que.push_back(s);
  while (!que.empty()) {
    int node = que.front();
    que.pop_front();
    for (int i = 0; i < G[node].size(); i++) {
      if (d1[G[node][i]] == N + 1) {
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
      if (d2[G[node][i]] == N + 1) {
        d2[G[node][i]] = d2[node] + 1;
        que.push_back(G[node][i]);
      }
    }
  }
  
  int shortest = d1[t];
  vector<int> r1(shortest - 1, 0);
  for (int i = 0; i < N; i++) {
    if (d1[i] < shortest - 1) {
      r1[d1[i]]++;
    }
  }
  
  vector<int> r2(shortest - 1, 0);
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