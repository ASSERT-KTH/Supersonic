#include <iostream>
#include <vector>
#include <bitset>
#include <unordered_set>

const int MAX_N = 51;
const int MAX_M = 101;
const int MAX_A = 3;

int N, M;
int A[MAX_A];
std::vector<std::unordered_set<int>> G(MAX_N);
std::vector<bool> used(MAX_N);
std::vector<std::vector<std::bitset<MAX_N>>> dp(MAX_M, std::vector<std::bitset<MAX_N>>(MAX_N));

int main() {
  std::cin >> N >> M;
  for (int i = 0; i < MAX_A; i++)
    std::cin >> A[i];
  for (int i = 0; i < M; i++) {
    int f, t;
    std::cin >> f >> t;
    f--;
    t--;
    G[f].insert(t);
  }
  for (int i = 0; i < N; i++)
    dp[0][i][i] = true;
  for (int i = 1; i < MAX_M; i++) {
    for (int j = 0; j < N; j++) {
      for (int k : G[j]) {
        if (dp[i - 1][j].any()) {
          dp[i][j] |= dp[i - 1][j] & dp[i - 1][k];
        }
      }
    }
  }
  used[N - 1] = true;
  for (int ite = 1;; ite++) {
    bool ok = false;
    std::vector<int> idx;
    for (int i = 0; i < N; i++) {
      if (used[i])
        continue;
      int cnt = 0;
      for (int j = 0; j < MAX_A; j++) {
        int a = A[j];
        for (int k = 0; k < N; k++) {
          if (dp[a][i][k] && used[k]) {
            cnt++;
            break;
          }
        }
      }
      if (cnt == MAX_A) {
        ok = true;
        idx.push_back(i);
      }
    }
    if (ok) {
      for (int i : idx) {
        used[i] = true;
      }
      if (used[0]) {
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