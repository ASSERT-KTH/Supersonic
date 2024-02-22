#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 51;
const int MAX_M = 51;
const int MAX_A = 3;
const int MAX_ITE = 100;

int N, M;
int A[MAX_A];
int G[MAX_N][MAX_N];
bool dp[MAX_ITE][MAX_N];
int used_count = 0;

int main() {
  cin >> N >> M;
  for (int i = 0; i < MAX_A; i++)
    cin >> A[i];
  for (int i = 0; i < M; i++) {
    int f, t;
    cin >> f >> t;
    f--;
    t--;
    G[f][t] = 1;
  }
  for (int i = 0; i < N; i++)
    dp[0][i] = true;
  for (int i = 1; i < MAX_ITE; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        if (dp[i - 1][j] && G[k][j]) {
          dp[i][k] = true;
        }
      }
    }
  }
  used_count++;
  for (int ite = 1; ite <= N; ite++) {
    bool ok = false;
    int idx[MAX_N];
    int idx_count = 0;
    for (int i = 0; i < N; i++) {
      if (used_count == N)
        break;
      if (dp[A[0]][i] && dp[A[1]][i] && dp[A[2]][i]) {
        ok = true;
        idx[idx_count++] = i;
      }
    }
    if (ok) {
      for (int l = 0; l < idx_count; l++) {
        int i = idx[l];
        used_count++;
      }
      if (dp[A[0]][0]) {
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