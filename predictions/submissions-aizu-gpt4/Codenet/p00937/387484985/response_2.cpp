#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 51;
constexpr int MAX_M = 101;

int N, M;
int A[3];
vector<int> G[MAX_N];
bitset<MAX_N> used;
bitset<MAX_N> dp[MAX_M][MAX_N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;

  for (int i = 0; i < 3; i++)
    cin >> A[i];

  for (int i = 0; i < M; i++) {
    int f, t;
    cin >> f >> t;
    f--; t--;
    G[f].push_back(t);
  }

  for (int i = 0; i < N; i++)
    dp[0][i].set(i);

  for (int i = 1; i < MAX_M; i++) {
    for (int j = 0; j < N; j++) {
      for (int& to : G[j]) {
        dp[i][j] |= dp[i - 1][to];
      }
    }
  }

  used.set(N - 1);

  for (int ite = 1;; ite++) {
    bitset<MAX_N> next_used;

    for (int i = 0; i < N; i++) {
      if (used[i]) continue;
      if ((dp[A[0]][i] & used).any() && (dp[A[1]][i] & used).any() && (dp[A[2]][i] & used).any()) {
        next_used.set(i);
      }
    }

    if (next_used.any()) {
      used |= next_used;
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