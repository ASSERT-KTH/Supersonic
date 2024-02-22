#include <bits/stdc++.h>
using namespace std;
int N, M;
int A[3];
bool graph[51][51];
bool used[51];
bool dp[101][51][51];

// use bfs or dfs to traverse the graph
void bfs(int start) {
    queue<int> q;
    q.push(start);
    used[start] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i = 0; i < N; i++) {
            if (graph[node][i] && !used[i]) {
                q.push(i);
                used[i] = true;
            }
        }
    }
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < 3; i++)
    cin >> A[i];
  memset(graph, false, sizeof(graph));
  for (int i = 0; i < M; i++) {
    int f, t;
    cin >> f >> t;
    f--;
    t--;
    graph[f][t] = true;
  }
  // rest of the code
}