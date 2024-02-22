#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[3];
vector<int> G[51];
bool used[51];
bool ****dp;

int main() {
  cin >> N >> M;
  for (int i = 0; i < 3; i++)
    cin >> A[i];

  // Allocate memory for dp array
  dp = new bool***[A[0] + 1];
  for (int i = 0; i <= A[0]; i++) {
    dp[i] = new bool**[A[1] + 1];
    for (int j = 0; j <= A[1]; j++) {
      dp[i][j] = new bool*[A[2] + 1];
      for (int k = 0; k <= A[2]; k++) {
        dp[i][j][k] = new bool[N];
        for (int l = 0; l < N; l++) {
          dp[i][j][k][l] = false;
        }
      }
    }
  }

  for (int i = 0; i < M; i++) {
    int f, t;
    cin >> f >> t;
    f--;
    t--;
    G[f].push_back(t);
  }

  for (int i = 0; i < N; i++)
    dp[0][0][0][i] = true;

  for (int a = 0; a <= A[0]; a++)
    for (int b = 0; b <= A[1]; b++)
      for (int c = 0; c <= A[2]; c++)
        for (int j = 0; j < N; j++) {
          if (a > 0 && dp[a - 1][b][c][j])
            for (int to : G[j])
              dp[a][b][c][to] = true;
          if (b > 0 && dp[a][b - 1][c][j])
            for (int to : G[j])
              dp[a][b][c][to] = true;
          if (c > 0 && dp[a][b][c - 1][j])
            for (int to : G[j])
              dp[a][b][c][to] = true;
        }

  used[N - 1] = true;
  for (int ite = 1;; ite++) {
    bool ok = false;
    for (int i = 0; i < N; i++) {
      if (used[i])
        continue;
      int cnt = 0;
      for (int j = 0; j < 3; j++) {
        int a = A[j];
        for (int k = 0; k < N; k++) {
          if (dp[a][a][a][k] && used[k]) {
            cnt++;
            break;
          }
        }
      }
      if (cnt == 3) {
        ok = true;
        used[i] = true;
        if (used[0]) {
          cout << ite << endl;
          return 0;
        }
      }
    }
    if (!ok) break;
  }

  cout << "IMPOSSIBLE" << endl;
  return 0;
}