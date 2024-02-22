#include <iostream>
#include <iomanip>
using namespace std;

void calculateWinRate(int a[2][9], int num[2][9], double& winrate1, double& winrate2, int depth) {
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
    if (num[0][i] == 0 && num[1][i] == 0) {
      num[0][i] = (a[0][depth] > a[1][i]) ? a[0][depth] + a[1][i] : 0;
      num[1][i] = (a[0][depth] <= a[1][i]) ? a[0][depth] + a[1][i] : 0;
      calculateWinRate(a, num, winrate1, winrate2, depth + 1);
      num[0][i] = 0;
      num[1][i] = 0;
    }
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
    calculateWinRate(a, num, winrate1, winrate2, 0);
    double ans = winrate1 / 362880;
    double ans2 = winrate2 / 362880;
    cout << fixed << setprecision(5) << ans << " " << ans2 << "\n";
  }
  return 0;
}