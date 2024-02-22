#include <iostream>
using namespace std;

int main() {
  const int INF = 1000000000;
  int n, c;
  static int dp1[5002][2], dp2[5002][2]; // two 2D arrays instead of one 3D array
  for (int j = 0; j < 5002; j++) {
    dp1[j][0] = INF;
    dp1[j][1] = INF;
    dp2[j][0] = INF;
    dp2[j][1] = INF;
  }
  dp1[1][0] = 0;
  dp1[0][1] = 0;
  int (*current)[2] = dp1;
  int (*previous)[2] = dp2;
  
  scanf("%d", &n);
  
  for (int i = 2; i <= n; i++) {
    scanf("%d", &c);
    for (int j = 0; j <= n / 2; j++) {
      if (j == 0)
        current[j][0] = INF;
      else
        current[j][0] = min(previous[j - 1][0], previous[j - 1][1] + c);
        
      current[j][1] = min(previous[j][0] + c, previous[j][1]);
    }
    swap(current, previous); // swap the pointers
  }
  printf("%d\n", min(previous[n / 2][0], previous[n / 2][1]));
}