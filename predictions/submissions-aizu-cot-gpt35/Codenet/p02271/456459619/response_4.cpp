#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int *N;
int n;
bool **memo; // Memoization table

bool solve(int i, int m) {
  if (i == n) {
    return m == 0 ? true : false;
  }
  
  if (memo[i][m] != -1) { // Check if the result is already memoized
    return memo[i][m];
  }
  
  bool result = solve(i + 1, m - N[i]) || solve(i + 1, m);
  memo[i][m] = result; // Memoize the result
  return result;
}

int main() {
  int t;
  scanf("%d", &n);
  N = (int *)calloc(n, sizeof(int));
  for (int i = 0; i < n; i++) {
    scanf("%d", &N[i]);
  }
  scanf("%d", &t);
  
  memo = new bool*[n]; // Create the memoization table
  for (int i = 0; i < n; i++) {
    memo[i] = new bool[t+1];
    memset(memo[i], -1, (t+1) * sizeof(bool)); // Initialize the table with -1
  }
  
  for (int i = 0; i < t; i++) {
    int p;
    scanf("%d", &p);
    if (solve(0, p)) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
  
  // Clean up the memoization table
  for (int i = 0; i < n; i++) {
    delete[] memo[i];
  }
  delete[] memo;
  
  // Clean up the array
  free(N);

  return 0;
}