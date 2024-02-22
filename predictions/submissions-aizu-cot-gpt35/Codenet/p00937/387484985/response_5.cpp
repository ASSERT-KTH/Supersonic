#include <iostream>
#include <vector>
using namespace std;

int N, M;
int A[3];
vector<int> G[51];
bool used[51];
bool dp[101][51];

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < 3; i++)
    scanf("%d", &A[i]);
  for (int i = 0; i < M; i++) {
    int f, t;
    scanf("%d%d", &f, &t);
    f--;
    t--;
    G[f].push_back(t);
  }
  for (int i = 0; i < N; i++)
    dp[0][i] = true;
  for (int i = 1; i < 101; i++) {
    for (int j = 0; j < N; j++) {
      if (dp[i - 1][j]) {
        for (int k = 0; k < N; k++) {
          if (dp[i - 1][j] && used[k]) {
            for (int to : G[k]) {
              dp[i][to] = true;
            }
          }
        }
      }
    }
  }
  used[N - 1] = true;
  for (int ite = 1; ; ite++) {
    bool ok = false;
    int idx[51];
    int idxSize = 0;
    for (int i = 0; i < N; i++) {
      if (used[i])
        continue;
      int cnt = 0;
      for (int j = 0; j < 3; j++) {
        int a = A[j];
        for (int k = 0; k < N; k++) {
          if (dp[a][i] && used[k]) {
            cnt++;
            break;
          }
        }
      }
      if (cnt == 3) {
        ok = true;
        idx[idxSize++] = i;
      }
    }
    if (ok) {
      for (int i = 0; i < idxSize; i++) {
        used[idx[i]] = true;
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