#include <iostream>
#include <vector>

int main() {
  int N, M;
  int A[3];
  std::vector<std::vector<int>> G;
  std::vector<bool> used;
  std::vector<std::vector<bool>> dp;
  
  std::cin >> N >> M;
  for (int i = 0; i < 3; i++)
    std::cin >> A[i];
  
  G.resize(N);
  dp.resize(101, std::vector<bool>(N, false));
  used.resize(N, false);
  
  for (int i = 0; i < M; i++) {
    int f, t;
    std::cin >> f >> t;
    f--;
    t--;
    G[f].push_back(t);
  }
  
  for (int i = 0; i < N; i++)
    dp[0][i] = true;
  
  for (int i = 1; i < 101; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        if (dp[i - 1][j] && dp[i - 1][j] == dp[i - 1][k]) {
          for (int to : G[k]) {
            dp[i][j] = true;
          }
        }
      }
    }
  }
  
  used[N - 1] = true;
  for (int ite = 1; ; ite++) {
    bool ok = false;
    std::vector<int> idx;
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