#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, t;
  scanf("%d", &n);
  vector<int> N(n, 0);
  for (int i = 0; i < n; i++) {
    scanf("%d", &N[i]);
  }
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int p;
    scanf("%d", &p);
    vector<vector<bool>> dp(n+1, vector<bool>(p+1, false));
    dp[0][0] = true;
    for(int i=1; i<=n; i++){
      dp[i][0] = true;
      for(int j=1; j<=p; j++){
        if(j<N[i-1]) dp[i][j] = dp[i-1][j];
        else dp[i][j] = dp[i-1][j] || dp[i-1][j-N[i-1]];
      }
    }
    if (dp[n][p]) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
}