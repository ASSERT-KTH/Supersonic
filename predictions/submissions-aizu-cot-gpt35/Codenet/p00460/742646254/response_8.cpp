#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

int main() {
  int const MOD = 100000;
  int N, M, S;
  while (cin >> N >> M >> S && (N | M | S)) {
    int** dp = new int*[N * N + 1];
    for (int i = 0; i <= N * N; i++) {
      dp[i] = new int[S + 1];
      memset(dp[i], 0, (S + 1) * sizeof(int));
    }

    dp[0][0] = 1;
    for (int currSum = 1; currSum <= S; currSum++) {
      for (int currIndex = 1; currIndex <= N * N; currIndex++) {
        for (int add = 1; add <= M; add++) {
          if (currSum >= add) {
            dp[currIndex][currSum] = (dp[currIndex][currSum] + dp[currIndex - 1][currSum - add]) % MOD;
          }
        }
      }
    }

    cout << dp[N * N][S] << endl;

    for (int i = 0; i <= N * N; i++) {
      delete[] dp[i];
    }
    delete[] dp;
  }
  
  return 0;
}