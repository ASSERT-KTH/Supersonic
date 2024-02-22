#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
int N, M;
int A[3];
vector<vector<int>> adjMatrix;
bool used[51];
queue<int> unusedNodes;
int main() {
  fast_io;
  scanf("%d %d", &N, &M);
  for (int i = 0; i < 3; i++)
    scanf("%d", &A[i]);
  adjMatrix.assign(N, vector<int>(N, 0));
  for (int i = 0; i < M; i++) {
    int f, t;
    scanf("%d %d", &f, &t);
    f--;
    t--;
    adjMatrix[f][t] = 1;
  }
  for (int i = 0; i < N; i++) {
    adjMatrix[i][i] = 1;
    unusedNodes.push(i);
  }
  vector<vector<int>> dp(101, vector<int>(N, 0));
  dp[0] = adjMatrix;
  for (int i = 1; i < 101; i++) {
    dp[i] = matrixMultiplication(dp[i - 1], adjMatrix);
  }
  used[N - 1] = true;
  for (int ite = 1;; ite++) {
    bool ok = false;
    int size = unusedNodes.size();
    for (int i = 0; i < size; i++) {
      int node = unusedNodes.front();
      unusedNodes.pop();
      if (used[node])
        continue;
      int cnt = 0;
      for (int j = 0; j < 3; j++) {
        int a = A[j];
        for (int k = 0; k < N; k++) {
          if (dp[a][node][k] && used[k]) {
            cnt++;
            break;
          }
        }
      }
      if (cnt == 3) {
        ok = true;
        used[node] = true;
        if (node == 0) {
          printf("%d\n", ite);
          return 0;
        }
      } else {
        unusedNodes.push(node);
      }
    }
    if (!ok)
      break;
  }
  printf("IMPOSSIBLE\n");
  return 0;
}