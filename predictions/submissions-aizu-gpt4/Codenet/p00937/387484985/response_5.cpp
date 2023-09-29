#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 51;
constexpr int MAXM = 101;

bool dp[MAXM][MAXN][MAXN] = {false};
bool used[MAXN] = {false};
vector<int> G[MAXN];
int A[3];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < 3; ++i) cin >> A[i];
  for (int i = 0, f, t; i < M; ++i) {
    cin >> f >> t; --f; --t;
    G[f].push_back(t);
  }
  for (int i = 0; i < N; ++i) dp[0][i][i] = true;
  for (int i = 1; i < MAXM; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < N; ++k) {
        if (dp[i - 1][j][k]) {
          for (int to : G[k]) {
            dp[i][j][to] = true;
          }
        }
      }
    }
  }
  used[N - 1] = true;
  for (int ite = 1;; ++ite) {
    bool ok = false;
    vector<int> idx;
    for (int i = 0; i < N; ++i) {
      if (used[i]) continue;
      int cnt = 0;
      for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < N; ++k) {
          if (dp[A[j]][i][k] && used[k]) {
            ++cnt;
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
      for (int i : idx) used[i] = true;
      if (used[0]) {
        cout << ite << "\n";
        return 0;
      }
    } else {
      break;
    }
  }
  cout << "IMPOSSIBLE\n";
  return 0;
}