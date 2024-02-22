#include <algorithm>
#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;
int n, x, a[30];
unordered_map<int, vector<bool>> dp;
vector<bool> prime;

void generatePrimes(int upto) {
  prime.resize(upto + 1, false);
  prime[0] = true;
  prime[2] = true;
  for (int i = 3; i <= upto; i += 2)
    prime[i] = true;
  for (int i = 3; i * i <= upto; i += 2) {
    if (!prime[i])
      continue;
    for (int j = i * i; j <= upto; j += i)
      prime[j] = false;
  }
}

vector<bool>& getDP(int target) {
  if (dp.find(target) == dp.end()) {
    dp[target].resize(target + 1, false);
    dp[target][0] = true;
    for (int i = 1; i <= target; i++) {
      for (int j = 0; j < n && i >= a[j]; j++) {
        if (dp[target][i - a[j]]) {
          dp[target][i] = true;
          break;
        }
      }
    }
  }
  return dp[target];
}

int main() {
  while (scanf("%d%d", &n, &x), n) {
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    if (prime.size() < x)
      generatePrimes(x);
    auto& targetDP = getDP(x);
    int i = x;
    while (i >= 0 && !(targetDP[i] && prime[i])) i--;
    printf(i >= 0 ? "%d\n" : "NA\n", i);
  }
}