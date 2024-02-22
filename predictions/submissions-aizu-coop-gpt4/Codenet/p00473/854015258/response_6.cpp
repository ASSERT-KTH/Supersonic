#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  const int INF = 1000000000;
  int n, c;
  int dp[5002][2] = { {INF, 0}, {0, INF} }; 
  cin >> n;

  for (int i = 2; i <= n; i++) {
    int s = i % 2, t = 1 - s;
    cin >> c;
    for (int j = 0; j <= n / 2; j++) {
      int t0 = dp[j - 1][0], t1 = dp[j - 1][1] + c;
      if (j == 0)
        dp[j][0] = INF;
      else
        dp[j][0] = min(t0, t1);
      
      int t2 = dp[j][0] + c, t3 = dp[j][1];
      dp[j][1] = min(t2, t3);
    }
  }
  cout << min(dp[n / 2][0], dp[n / 2][1]) << endl;
}