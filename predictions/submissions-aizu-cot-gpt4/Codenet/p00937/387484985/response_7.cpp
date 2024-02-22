#include <iostream>
#include <vector>
#include <cstring>
using std::vector;

int main() {
  int N, M;
  scanf("%d %d",&N,&M);
  int A[3];
  for (int i = 0; i < 3; i++)
    scanf("%d",&A[i]);
  vector<int> G[51];
  for (int i = 0; i < M; i++) {
    int f, t;
    scanf("%d %d",&f,&t);
    f--;
    t--;
    G[f].push_back(t);
  }
  bool dp[101][51][51];
  memset(dp, false, sizeof(dp));
  for (int i = 0; i < N; i++)
    dp[0][i][i] = true;
  for (int i = 1; i < 101; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        if (dp[i - 1][j][k]) {
          for (int to : G[k]) {
            dp[i][j][to] = true;
          }
        }
      }
    }
  }
  bool used[51];
  memset(used, false, sizeof(used));
  used[N - 1] = true;
  vector<int> idx;
  idx.reserve(N);
  for (int ite = 1;; ite++) {
    bool ok = false;
    idx.clear();
    for (int i = 0; i < N; i++) {
      if (used[i])
        continue;
      int cnt = 0;
      for (int j = 0; j < 3; j++) {
        int a = A[j];
        for (int k = 0; k < N; k++) {
          if (dp[a][i][k] && used[k]) {
            cnt++;
            break;
          }
        }
      }
      if (cnt == 3) {
        ok = true;
        idx.push_back(i);
      }
    }
    if (ok) {
      for (int i : idx) {
        used[i] = true;
      }
      if (used[0]) {
        printf("%d\n", ite);
        return 0;
      }
    } else {
      break;
    }
  }
  printf("IMPOSSIBLE\n");
  return 0;
}