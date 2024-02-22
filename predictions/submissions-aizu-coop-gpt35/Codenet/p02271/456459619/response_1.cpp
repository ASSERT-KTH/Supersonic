#include <iostream>
using namespace std;

const int MAX_N = 100;
int N[MAX_N];
int n;

bool solve(int i, int m) {
  // Base cases
  if (m == 0) {
    return true;
  }
  if (i >= n || m < 0) {
    return false;
  }
  
  // Check if the subproblem is already solved
  // and return the cached result if available
  // (Memoization / Dynamic Programming)
  // We can use a 2D array to store the results
  static bool dp[MAX_N][MAX_N];
  if (dp[i][m]) {
    return dp[i][m];
  }
  
  // Recursive cases
  bool included = solve(i + 1, m - N[i]);
  bool excluded = solve(i + 1, m);
  
  // Cache the result for future use
  dp[i][m] = included || excluded;
  
  return dp[i][m];
}

int main() {
  int t;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> N[i];
  }
  cin >> t;
  for (int i = 0; i < t; i++) {
    int p;
    cin >> p;
    if (solve(0, p)) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
}