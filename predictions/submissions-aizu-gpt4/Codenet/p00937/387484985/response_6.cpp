#include <bits/stdc++.h>
using namespace std;
const int MAXN = 51;
const int MAXM = 101;
int N, M;
int A[3];
vector<int> G[MAXN];
bitset<MAXN> used;
bitset<MAXN> dp[MAXM][MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
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
    dp[0][i][i] = true;
  for (int i = 1; i < MAXM; i++) {
    for (int j = 0; j < N; j++) {
      dp[i][j] = dp[i - 1][j];
      for (int k : G[j]) {
        dp[i][k] |= dp[i - 1][j];
      }
    }
  }
  used[N - 1] = true;
  for (int ite = 1;; ite++) {
    bool ok = false;
    vector<int> idx;
    for (int i = 0; i < N; i++) {
      if (used[i])
        continue;
      int cnt = 0;
      for (int j = 0; j < 3; j++) {
        if (dp[A[j]][i] & used) {
          cnt++;
          if (cnt == 3) {
            ok = true;
            idx.push_back(i);
            break;
          }
        }
      }
    }
    if (ok) {
      for (int i : idx) {
        used[i] = true;
      }
      if (used[0]) {
        cout << ite << '\n';
        return 0;
      }
    } else {
      break;
    }
  }
  cout << "IMPOSSIBLE" << '\n';
  return 0;
}