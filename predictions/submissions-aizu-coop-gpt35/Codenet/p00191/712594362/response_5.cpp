#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

const int MAX_N = 101;

int n, m;
double dp[MAX_N][MAX_N];
double t[MAX_N][MAX_N];

double solve(int times, int prev) {
  // Check if the probability has already been calculated
  if (dp[times][prev] >= 0)
    return dp[times][prev];

  // Base case: reach the maximum number of steps
  if (times == m)
    return dp[times][prev] = 1;

  double maxProb = -1;
  for (int i = 0; i < n; i++) {
    double prob;
    if (times == 0) {
      prob = solve(times + 1, i) * 1;
    } else {
      prob = solve(times + 1, i) * t[prev][i];
    }
    maxProb = max(maxProb, prob);
  }

  // Store the calculated probability in the dp array for future use
  return dp[times][prev] = maxProb;
}

int main(void) {
  while (cin >> n >> m) {
    if (n == 0 && m == 0)
      break;

    // Initialize only the portion of the dp array that is used
    for (int i = 0; i <= m; i++) {
      for (int j = 0; j < n; j++) {
        dp[i][j] = -1;
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> t[i][j];
      }
    }

    double maxProb = solve(0, 0) * 100;
    printf("%.2lf\n", round(maxProb) / 100);
  }
}