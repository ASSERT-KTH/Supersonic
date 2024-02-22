#include <algorithm>
#include <iostream>
#define INF 1 << 28
using namespace std;
int p[1000001];
int memo[1000001][6];
int memo2[1000001];

int solve(int n, int count) {
  for(int i=1;i<=n;++i){
    for(int j=1;j<=count;++j){
      if(p[i] > j)
        memo[i][j] = memo[i-1][j];
      else
        memo[i][j] = min(memo[i-1][j], memo[i-p[i]][j-1]+1);
    }
  }
  return memo[n][count];
}

int solve2(int n) {
  for(int i=1;i<=n;++i){
    for(int j=0;p[j]<=i;++j){
      if(p[j]%2==0)
        continue;
      else
        memo2[i] = min(memo2[i], memo2[i-p[j]]+1);
    }
  }
  return memo2[n];
}

int main() {
  int n;
  for (int i = 0; i <= 1000000; i++)
    p[i] = (i*(i+1)/2)*(i*(i+1)/2); // using formula of cubes of natural numbers.
  for (int i = 1; i <= 1000000; i++)
    solve2(i);
  while (cin >> n, n)
    cout << solve(n, 5) << " " << solve2(n) << endl;
}