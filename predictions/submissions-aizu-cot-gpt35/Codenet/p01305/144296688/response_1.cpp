#include <iostream>
using namespace std;

double calculateWinRate(int num[2][9], int a[2][9], int depth) {
  if (depth == 9) {
    int geitu = 0, jacky = 0;
    for (int m = 0; m < 9; m++) {
      geitu += num[0][m];
      jacky += num[1][m];
    }
    if (geitu > jacky)
      return 1.0;
    else if (geitu < jacky)
      return 0.0;
    else
      return 0.5;
  }

  double winrate1 = 0.0;
  for (int z = 0; z < 9; z++) {
    if (num[0][depth] != 0 || num[1][z] != 0)
      continue;
    num[0][depth] = a[0][depth] + a[1][z];
    num[1][z] = a[0][depth] + a[1][z];
    winrate1 += calculateWinRate(num, a, depth + 1);
    num[0][depth] = 0;
    num[1][z] = 0;
  }

  return winrate1;
}

int main() {
  int n;
  cin >> n;
  for (int l = 0; l < n; l++) {
    int num[2][9], a[2][9];
    double winrate1 = 0, winrate2 = 0;
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 9; k++)
        cin >> a[j][k];
    }
    winrate1 = calculateWinRate(num, a, 0);
    winrate2 = 362880 - winrate1;
    double ans = winrate1 / 362880;
    double ans2 = winrate2 / 362880;
    cout << fixed;
    cout.precision(5);
    cout << ans << " " << ans2 << "\n";
  }
  return 0;
}