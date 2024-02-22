#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[3];
vector<int> G[51];
bitset<51> used;
bitset<101*51*51> dp;

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
    dp[i*N + i] = true;
  for (int i = 1; i < 101; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        if (dp[(i - 1)*N*N + j*N + k]) {
          for (int to : G[k]) {
            dp[i*N*N + j*N + to] = true;
          }
        }
      }
    }
  }
  used[N - 1] = true;
  for (int ite = 1;; ite++) {
    vector<int> idx;
    for (int i = 0; i < N; i++) {
      if (used[i])
        continue;
      int cnt = 0;
      for (int j = 0; j < 3; j++) {
        int a = A[j];
        for (int k = 0; k < N; k++) {
          if (dp[a*N*N + i*N + k] && used[k]) {
            cnt++;
            break;
          }
        }
      }
      if (cnt == 3) {
        idx.push_back(i);
      }
    }
    if (!idx.empty()) {
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