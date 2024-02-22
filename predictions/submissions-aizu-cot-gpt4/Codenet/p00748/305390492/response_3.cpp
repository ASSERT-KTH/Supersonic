#include <iostream>
#define INF 10000000
using namespace std;
int p[1000001];
int memo[1000001][6];
int memo2[1000001];

int solve(int n, int count) {
  for(int i=0; i<=n; i++) {
    for(int j=0; j<=count; j++) {
      if(i==0) memo[i][j] = 0;
      else if(j==0 || i<0) memo[i][j] = INF;
      else {
        if(p[j-1] <= i) {
          memo[i][j] = min(memo[i][j-1], memo[i - p[j-1]][j-1] + 1);
        } else {
          memo[i][j] = memo[i][j-1];
        }
      }
    }
  }
  return memo[n][count];
}

int solve2(int n) {
  for(int i=0; i<=n; i++) {
    if(i==0) memo2[i] = 0;
    else if(i<0) memo2[i] = INF;
    else {
      for (int j = 1; j <= i; j++) {
        if (j % 2 != 0 && p[j] <= i) {
          int res = memo2[i - p[j]] + 1;
          if (res < memo2[i]) {
            memo2[i] = res;
          }
        }
      }
    }
  }
  return memo2[n];
}

int main() {
  int n;
  for (int i = 0; i <= 1000000; i++)
    p[i] = i * (i + 1) * (i + 2) / 6;
  while (cin >> n, n)
    cout << solve(n, 5) << " " << solve2(n) << endl;
}