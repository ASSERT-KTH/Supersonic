#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 51;

int N, M;
int A[3];
vector<int> G[MAX_N];
bool used[MAX_N];
bool dp[MAX_N][MAX_N];

int main() {
  cin >> N >> M;
  for (int i = 0; i < 3; i++)
    cin >> A[i];
  for (int i = 0; i < M; i++) {
    int f, t;
    cin >> f >> t;
    f--;
    t--;
    G[f].push_back(t);
  }
  for (int i = 0; i < N; i++)
    dp[0][i] = true;
  for (int a = 1; a <= 100; a++) {
    for (int i = 0; i < N; i++) {
      if (!dp[a - 1][i])
        continue;
      int cnt = 0;
      for (int k = 0; k < N; k++) {
        if (used[k] && dp[a - 1][i][k])
          cnt++;
        if (cnt >= 3)
          break;
      }
      if (cnt >= 3)
        dp[a][i] = true;
    }
  }
  used[N - 1] = true;
  for (int ite = 1; ite <= N; ite++) {
    bool ok = false;
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
        if (cnt >= 3)
          break;
      }
      if (cnt >= 3) {
        used[i] = true;
        if (used[0]) {
          cout << ite << endl;
          return 0;
        }
        ok = true;
      }
    }
    if (!ok)
      break;
  }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}