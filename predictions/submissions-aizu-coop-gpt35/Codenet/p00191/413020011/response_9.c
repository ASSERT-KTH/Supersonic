double solve(int n, int m, int k, int p) {
  double res;
  
  if (m == 1)
    return 1;
  
  if (memo[p][m][k] > 0)
    return memo[p][m][k];
  
  res = 0;
  
  rep(i, n)
    res = MAX(res, solve(n, m - 1, p, i) * a[p][i]);
  
  return memo[p][m][k] = res;
}