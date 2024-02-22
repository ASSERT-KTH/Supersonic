#include <iostream>
using namespace std;

int main() {
  const int INF = 1000000000;
  int n, c;
  static int prev[5002][2];
  static int curr[5002][2];

  for (int j = 0; j < 5002; j++) {
    prev[j][0] = INF;
    prev[j][1] = INF;
  }
  prev[1][0] = 0;
  prev[0][1] = 0;

  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    int s = i % 2;
    scanf("%d", &c);

    int prev0 = prev[0][0];
    int prev1 = prev[0][1];
    curr[0][0] = INF;

    for (int j = 1; j <= n / 2; j++) {
      curr[j][0] = min(prev0, prev1 + c);
      curr[j][1] = min(prev[j][0] + c, prev[j][1]);

      prev0 = curr[j][0];
      prev1 = curr[j][1];
    }

    swap(prev, curr);
  }

  printf("%d\n", min(prev[n / 2][0], prev[n / 2][1]));
}