#include <iostream>
#include <queue>
#include <vector>
#include <omp.h>
#define INF (1 << 23)
using namespace std;

int main() {
  int N, M, s, t, u, v;
  cin >> N >> M >> s >> t;
  s--;
  t--;
  vector<vector<int>> G(N);
  vector<int> size(N);
  for (int i = 0; i < M; i++) {
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
    size[u]++;
    size[v]++;
  }
  vector<int> d1(N, INF), d2(N, INF);
  d1[s] = 0;
  d2[t] = 0;
  vector<bool> visited1(N, false), visited2(N, false);
  visited1[s] = true;
  visited2[t] = true;
  queue<int> que1, que2;
  que1.push(s);
  que2.push(t);
  #pragma omp parallel sections
  {
    #pragma omp section
    {
      while (!que1.empty()) {
        int node = que1.front();
        que1.pop();
        for (int i = 0; i < size[node]; i++) {
          int next = G[node][i];
          if (!visited1[next]) {
            d1[next] = d1[node] + 1;
            visited1[next] = true;
            que1.push(next);
          }
        }
      }
    }
    #pragma omp section
    {
      while (!que2.empty()) {
        int node = que2.front();
        que2.pop();
        for (int i = 0; i < size[node]; i++) {
          int next = G[node][i];
          if (!visited2[next]) {
            d2[next] = d2[node] + 1;
            visited2[next] = true;
            que2.push(next);
          }
        }
      }
    }
  }
  // rest of the code remains the same
}