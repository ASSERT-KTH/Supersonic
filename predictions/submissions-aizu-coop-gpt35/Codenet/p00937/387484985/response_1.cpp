#include <iostream>
#include <vector>
#include <algorithm>

constexpr int MAX_N = 51;
constexpr int MAX_M = 101;

int N, M;
int A[3];
std::vector<int> G[MAX_N];
bool used[MAX_N];
bool dp[MAX_M][MAX_N];

int main() {
  std::cin >> N >> M;
  for (int i = 0; i < 3; i++)
    std::cin >> A[i];
  for (int i = 0; i < M; i++) {
    int f, t;
    std::cin >> f >> t;
    f--;
    t--;
    G[f].push_back(t);
  }

  for (int i = 0; i < N; i++)
    dp[0][i] = true;

  for (int i = 1; i < M; i++) {
    for (int j = 0; j < N; j++) {
      for (int to : G[j]) {
        dp[i][to] |= dp[i - 1][j];
      }
    }
  }

  used[0] = true;
  for (int ite = 1;; ite++) {
    bool ok = false;
    std::vector<int> idx;
    for (int i = 0; i < N; i++) {
      if (used[i])
        continue;
      int cnt = 0;
      for (int j = 0; j < 3; j++) {
        int a = A[j];
        if (dp[a][i] && used[a]) {
          cnt++;
          break;
        }
      }
      if (cnt == 3) {
        ok = true;
        idx.push_back(i);
      }
    }
    if (ok) {
      for (int i : idx) {
        used[i] = true;
      }
      if (used[N - 1]) {
        std::cout << ite << std::endl;
        return 0;
      }
    } else {
      break;
    }
  }
  std::cout << "IMPOSSIBLE" << std::endl;
  return 0;
}