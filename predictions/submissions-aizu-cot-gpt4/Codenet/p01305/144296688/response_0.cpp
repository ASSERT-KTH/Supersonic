#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int l = 0; l < n; l++) {
    int num[2][9], a[2][9], geitu, jacky;
    double winrate1 = 0, winrate2 = 0;
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 9; k++)
        cin >> a[j][k];
    }
    for (int z = 0; z < 9; z++) {
      num[0][0] = num[1][0] = 0;
      num[0][0] = max(a[0][0], a[1][z]);
      num[1][0] = a[0][0] + a[1][z] - num[0][0];
      for (int b = 0; b < 9; b++) {
        if (b == z)
          continue;
        num[0][1] = num[1][1] = 0;
        num[0][1] = max(a[0][1], a[1][b]);
        num[1][1] = a[0][1] + a[1][b] - num[0][1];
        // ... Repeat this pattern for the rest of the nested loops ...
        for (int m = 0; m < 9; m++) {
          geitu += num[0][m];
          jacky += num[1][m];
        }
        if (geitu > jacky)
          winrate1++;
        else if (geitu < jacky)
          winrate2++;
      }
    }
    double ans = ((int) ((winrate1 / 362880) * 100000 + 0.5)) / 100000;
    double ans2 = ((int) ((winrate2 / 362880) * 100000 + 0.5)) / 100000;
    cout << ans << " " << ans2 << "\n";
  }
  return 0;
}