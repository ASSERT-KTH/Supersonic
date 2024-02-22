#include <iostream>
using namespace std;

int main() {
  const int INF = 1000000000;
  int n, c;
  static int dp0[5002][2], dp1[5002][2];
  
  // Initialization
  for (int j = 0; j < 5002; j++) {
    dp0[j][0] = INF;
    dp0[j][1] = INF;
    dp1[j][0] = INF;
    dp1[j][1] = INF;
  }
  dp1[1][0] = 0;
  dp1[0][1] = 0;

  // Read input
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    int s = i % 2, t = 1 - s;
    scanf("%d", &c);
    for (int j = 0; j <= n / 2; j++) {
      if (j == 0)
        (s ? dp1 : dp0)[j][0] = INF;
      else
        (s ? dp1 : dp0)[j][0] = min((t ? dp1 : dp0)[j - 1][0], (t ? dp1 : dp0)[j - 1][1] + c);
      (s ? dp1 : dp0)[j][1] = min((t ? dp1 : dp0)[j][0] + c, (t ? dp1 : dp0)[j][1]);
    }
  }
  
  // Output result
  printf("%d\n", min(dp0[n / 2][0], dp0[n / 2][1]));
}