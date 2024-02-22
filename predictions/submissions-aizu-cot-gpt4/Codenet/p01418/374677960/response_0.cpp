#include <bits/stdc++.h>
using namespace std;

int K, R, L;
double P, E, T;
double dp[1000][1000];  // Assuming the maximum value of d and l is less than 1000.

bool isCalculated[1000][1000];  // To check if a state is already calculated.

double dfs(int d, double l, double r) {
  double mid = (l + r) / 2;
  if (!d)
    return (T - E < mid && mid < T + E) ? 1 : 0;
  if (r < T - E || T + E < l)
    return 0;
    
  // If value is already calculated, return it.
  if(isCalculated[d][l]) 
    return dp[d][l];

  // Else calculate and store it.
  if (mid >= T)
    dp[d][l] = (1.0 - P) * dfs(d - 1, l, mid) + P * dfs(d - 1, mid, r);
  else
    dp[d][l] = (1.0 - P) * dfs(d - 1, mid, r) + P * dfs(d - 1, l, mid);

  // Mark the state as calculated.
  isCalculated[d][l] = true;

  return dp[d][l];
}

int main() {
  cin >> K >> L >> R >> P >> E >> T;
  printf("%.9f\n", dfs(K, L, R));
  return 0;
}