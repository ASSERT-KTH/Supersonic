#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  constexpr int MAX_N = 4000;
  constexpr int MAX_PARTS = 4;

  // Use bitset for dp array
  vector<bitset<MAX_PARTS + 1>> dp(MAX_N + 1);

  // Initialize dp array
  for (int i = 0; i <= MAX_PARTS; i++) {
    dp[0][i] = 1;
  }

  // Calculate dp values
  for (int i = 1; i <= MAX_PARTS; i++) {
    for (int j = 1; j <= MAX_N; j++) {
      for (int k = 0; k <= j && k <= 1000; k++) {
        dp[j][i] |= dp[j - k][i - 1];
      }
    }
  }

  // Process input
  int n;
  while (cin >> n) {
    cout << dp[n][MAX_PARTS].count() << endl;
  }

  return 0;
}