#include <iostream>
#include <iomanip>
#include <vector>

double dfs(int d, double l, double r, std::vector<std::vector<double>>& memo, double P, double T, double E) {
  double mid = (l + r) / 2;
  
  if (!d)
    return (T - E < mid && mid < T + E) ? 1 : 0;
  
  if (r < T - E || T + E < l)
    return 0;
  
  if (memo[d][mid] != -1)
    return memo[d][mid];
  
  double result;
  
  if (mid >= T)
    result = (1.0 - P) * dfs(d - 1, l, mid, memo, P, T, E) + P * dfs(d - 1, mid, r, memo, P, T, E);
  else
    result = (1.0 - P) * dfs(d - 1, mid, r, memo, P, T, E) + P * dfs(d - 1, l, mid, memo, P, T, E);
  
  memo[d][mid] = result;
  return result;
}

int main() {
  int K, R, L;
  double P, E, T;
  std::cin >> K >> L >> R >> P >> E >> T;
  
  std::vector<std::vector<double>> memo(K + 1, std::vector<double>(R + 1, -1));
  
  double result = dfs(K, L, R, memo, P, T, E);
  
  std::cout << std::setprecision(9) << result << std::endl;
  
  return 0;
}