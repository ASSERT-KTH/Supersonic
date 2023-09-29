#include <bits/stdc++.h>
using namespace std;
int K, R, L;
double P, E, T;
double memo[105][1005];
double dfs(int d, double l, double r) {
  double mid = (l + r) / 2;
  if (!d)
    return (T - E < mid && mid < T + E) ? 1 : 0;
  if (r < T - E || T + E < l)
    return 0;
  if(memo[d][(int)(mid*1000)]!=-1)
    return memo[d][(int)(mid*1000)];
  double res=0;
  if (mid >= T)
    res=(1.0 - P) * dfs(d - 1, l, mid) + P * dfs(d - 1, mid, r);
  else
    res=(1.0 - P) * dfs(d - 1, mid, r) + P * dfs(d - 1, l, mid);
  memo[d][(int)(mid*1000)]=res;
  return res;
}
main() {
  cin >> K >> L >> R >> P >> E >> T;
  memset(memo,-1,sizeof(memo));
  printf("%.9f\n", dfs(K, L, R));
}