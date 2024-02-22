#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

int N, M;
std::array<int, 3> A;
std::vector<int> G[51];
bool used[51];
bool dp[101][51][51];
std::vector<int> unused;

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
    dp[0][i][i] = true;
  for (int i = 1; i < 101; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        if (dp[i - 1][j][k]) {
          for (int to : G[k]) {
            dp[i][j][to] = true;
          }
        }
      }
    }
  }
  used[N - 1] = true;
  for(int i = 0; i < N; i++) {
    if(!used[i])
      unused.push_back(i);
  }
  for (int ite = 1; !unused.empty(); ite++) {
    std::vector<int> next_unused;
    for (int i : unused) {
      int cnt = std::count_if(A.begin(), A.end(), [&](int a){
        return std::any_of(G[i].begin(), G[i].end(), [&](int k){
          return dp[a][i][k] && used[k];
        });
      });
      if (cnt == 3) {
        used[i] = true;
      } else {
        next_unused.push_back(i);
      }
    }
    unused = std::move(next_unused);
  }
  if (used[0]) {
    std::cout << "IMPOSSIBLE" << std::endl;
  } else {
    std::cout << "POSSIBLE" << std::endl;
  }
  return 0;
}