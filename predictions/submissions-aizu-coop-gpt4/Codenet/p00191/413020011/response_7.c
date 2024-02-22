#include <iostream>
#include <unordered_map>
#include <cstring>

double a[101][101];
std::unordered_map<int, double> memo;

double solve(int n, int m, int k, int p) {
  double res;
  int i, j;

  if (m == 1)
    return 1;

  int hash_key = p*10000 + m*100 + k;
  if (memo.find(hash_key) != memo.end())
    return memo[hash_key];

  res = 0;
  for(i = 0; i < n; i++) {
    double temp_res = solve(n, m - 1, p, i) * a[p][i];
    res = (temp_res > res) ? temp_res : res;
  }

  memo[hash_key] = res;
  return res;
}

int main(void) {
  int n, m, i, j, k;
  double res;
  while (std::cin >> n >> m, n | m) {
    memo.clear();
    for(i = 0; i < n; i++)
      for(j = 0; j < n; j++) 
        std::cin >> a[i][j];
    res = 0;
    for(i = 0; i < n; i++)
      for(j = 0; j < n; j++) {
        double temp_res = solve(n, m, i, j);
        res = (temp_res > res) ? temp_res : res;
      }
    printf("%.2f\n", res);
  }
  return 0;
}