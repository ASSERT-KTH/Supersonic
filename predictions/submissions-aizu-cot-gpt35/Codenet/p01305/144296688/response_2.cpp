#include <cstdlib>
#include <iostream>
using namespace std;

void calculateWinRate(int index, int permutation[], double& winrate1, double& winrate2, int a[][9]) {
  if (index == 9) {
    int num[2][9] = {{0}};
    for (int i = 0; i < 9; i++) {
      if (a[0][i] > a[1][permutation[i]])
        num[0][i] = (a[0][i] + a[1][permutation[i]]);
      else
        num[1][i] = (a[0][i] + a[1][permutation[i]]);
    }
    int geitu = 0, jacky = 0;
    for (int m = 0; m < 9; m++) {
      geitu += num[0][m];
      jacky += num[1][m];
    }
    if (geitu > jacky)
      winrate1++;
    else if (geitu < jacky)
      winrate2++;
  } else {
    for (int i = 0; i < 9; i++) {
      bool found = false;
      for (int j = 0; j < index; j++) {
        if (permutation[j] == i) {
          found = true;
          break;
        }
      }
      if (!found) {
        permutation[index] = i;
        calculateWinRate(index + 1, permutation, winrate1, winrate2, a);
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  for (int l = 0; l < n; l++) {
    int a[2][9];
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 9; k++)
        cin >> a[j][k];
    }
    double winrate1 = 0, winrate2 = 0;
    int permutation[9];
    calculateWinRate(0, permutation, winrate1, winrate2, a);
    double ans = winrate1 / 362880;
    double ans2 = winrate2 / 362880;
    cout << fixed;
    cout.precision(5);
    cout << ans << " " << ans2 << "\n";
  }
  return 0;
}