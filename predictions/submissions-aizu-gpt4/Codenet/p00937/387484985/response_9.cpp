#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int MAX_NODES = 51;
constexpr int MAX_ITERATIONS = 101;

int N, M;
int A[3];
vector<int> G[MAX_NODES];
bool used[MAX_NODES];
bool dp[MAX_ITERATIONS][MAX_NODES][MAX_NODES];

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
  fill(&dp[0][0][0], &dp[0][0][0] + sizeof(dp) / sizeof(bool), false);
  for (int i = 0; i < N; i++)
    dp[0][i][i] = true;
  for (int i = 1; i < MAX_ITERATIONS; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        if (dp[i - 1][j][k]) {
          for (const auto &to : G[k]) {
            dp[i][j][to] = true;
          }
        }
      }
    }
  }
  fill(used, used + sizeof(used) / sizeof(bool), false);
  used[N - 1] = true;
  for (int ite = 1;; ite++) {
    bool ok = false;
    vector<int> idx;
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
        idx.push_back(i);
      }
    }
    if (ok) {
      for (const auto &i : idx) {
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