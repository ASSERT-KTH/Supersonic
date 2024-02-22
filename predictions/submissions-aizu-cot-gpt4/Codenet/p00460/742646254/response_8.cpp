#include <iostream>
#include <vector>
using namespace std;
const int inf = 1 << 29;
int main() {
  int const MOD = 100000;
  vector<vector<int>> dp(55, vector<int>(3030, 0));
  for (int N, M, S; cin >> N >> M >> S && (N | M | S);) {
    for(auto& v: dp)
        fill(v.begin(), v.end(), 0);
    dp[0][0] = 1;
    int maxIndex = N * N;
    for (int add = 1; add <= M; ++add) {
      for (int currIndex = maxIndex; currIndex >= 1; --currIndex) {
        for (int currSum = add; currSum <= S; ++currSum) {
          (dp[currIndex][currSum] += dp[currIndex - 1][currSum - add]) %= MOD;
        }
      }
    }
    cout << dp[maxIndex][S] << endl;
  }
  return 0;
}