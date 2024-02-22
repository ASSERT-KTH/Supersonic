#include <iostream>
#include <bitset>

using namespace std;

int N, M;
int A[3];
bitset<51> G[51];
bool used[51];
bool dp[101][51][51];

int main() {
  cin >> N >> M;
  for (int i = 0; i < 3; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < M; i++) {
    int f, t;
    cin >> f >> t;
    f--;
    t--;
    G[f][t] = true;
  }
  for (int i = 0; i < N; i++) {
    dp[0][i][i] = true;
  }
  for (int i = 1; i < 101; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        if (dp[i - 1][j][k]) {
          for (int to = 0; to < N; to++) {
            if (G[k][to]) {
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
    int cnt = 0;
    for (int i = 0; i < N; i++) {
      if (used[i]) {
        cnt++;
        continue;
      }
      int a1 = A[0], a2 = A[1], a3 = A[2];
      for (int k = 0; k < N; k++) {
        if (dp[a1][i][k] && dp[a2][i][k] && dp[a3][i][k]) {
          ok = true;
          used[i] = true;
          break;
        }
      }
      if (ok) {
        break;
      }
    }
    if (cnt == N) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
    if (used[0]) {
      cout << ite << endl;
      return 0;
    }
  }
}