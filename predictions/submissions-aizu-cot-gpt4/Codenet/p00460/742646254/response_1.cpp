#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

int main() {
  const int MOD = 100000;
  vector<vector<int64_t>> dp(55, vector<int64_t>(3030, 0));

  for (int N, M, S; cin >> N >> M >> S && (N | M | S);) {
    for(auto &v : dp) 
      fill(v.begin(), v.end(), 0);
    dp[0][0] = 1;
    int total = N * N;
    for (int add = 1; add <= M; ++add) {
      for (int currIndex = total; currIndex >= 1; --currIndex) {
        for (int currSum = add; currSum <= S; ++currSum) {
          (dp[currIndex][currSum] += dp[currIndex - 1][currSum - add]) %= MOD;
        }
      }
    }
    cout << dp[total][S] << endl;
  }
  return 0;
}