#include <iostream>
using namespace std;

void calculateWinRates(int a[2][9], int num[2][9], int z, double& winrate1, double& winrate2, int depth) {
  if (depth == 9) {
    int geitu = 0, jacky = 0;
    for (int m = 0; m < 9; m++) {
      geitu += num[0][m];
      jacky += num[1][m];
    }
    if (geitu > jacky)
      winrate1++;
    else if (geitu < jacky)
      winrate2++;
    return;
  }

  for (int i = 0; i < 9; i++) {
    if (i == z)
      continue;
    num[0][depth] = 0;
    num[1][depth] = 0;
    if (a[0][depth] > a[1][i])
      num[0][depth] = (a[0][depth] + a[1][i]);
    else
      num[1][depth] = (a[0][depth] + a[1][i]);
    calculateWinRates(a, num, z, winrate1, winrate2, depth + 1);
  }
}

int main() {
  int n;
  cin >> n;
  for (int l = 0; l < n; l++) {
    int a[2][9], num[2][9];
    double winrate1 = 0, winrate2 = 0;
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 9; k++)
        cin >> a[j][k];
    }
    for (int z = 0; z < 9; z++) {
      calculateWinRates(a, num, z, winrate1, winrate2, 0);
    }
    double ans = winrate1 / 362880;
    double ans2 = winrate2 / 362880;
    cout << ans << " " << ans2 << "\n";
  }
  return 0;
}