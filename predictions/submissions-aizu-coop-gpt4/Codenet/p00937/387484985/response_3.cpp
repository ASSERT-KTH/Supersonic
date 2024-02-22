#include <iostream>
using namespace std;
int N, M;
int A[3];
int G[51][51];
bool used[51];
bool dp[101][51][51];
int main() {
  cin >> N >> M;
  for (int i = 0; i < 3; i++)
    cin >> A[i];
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      G[i][j] = -1;
  for (int i = 0; i < M; i++) {
    int f, t;
    cin >> f >> t;
    f--;
    t--;
    G[f][t] = true;
  }
  for (int i = 0; i < N; i++)
    dp[0][i][i] = true;
  for (int i = 1; i < 101; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        if (dp[i - 1][j][k]) {
          for (int to = 0; to < N; to++) {
            if (G[k][to] != -1) {
              dp[i][j][to] = true;
            }
          }
        }
      }
    }
  }
  used[N - 1] = true;
  for (int ite = 1;; ite++) {
    bool ok = false;
    bool new_used[51] = {false};
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
        new_used[i] = true;
      }
    }
    if (ok) {
      for (int i = 0; i < N; i++) {
        if (new_used[i]) {
          used[i] = true;
        }
      }
      if (used[0]) {
        cout << ite << endl;
        return 0;
      }
    } else {
      break;
    }
  }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}