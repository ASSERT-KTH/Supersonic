#include <cstdlib>
#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  int num[2][9], a[2][9];
  double winrate1 = 0, winrate2 = 0;
  for (int l = 0; l < n; l++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 9; k++)
        cin >> a[j][k];
    }
    for (int z = 0; z < 9; z++) {
      num[0][0] = a[0][0] > a[1][z] ? (a[0][0] + a[1][z]) : 0;
      num[1][0] = a[0][0] <= a[1][z] ? (a[0][0] + a[1][z]) : 0;
      for (int b = 0; b < 9; b++) {
        if (b == z)
          continue;
        num[0][1] = a[0][1] > a[1][b] ? (a[0][1] + a[1][b]) : 0;
        num[1][1] = a[0][1] <= a[1][b] ? (a[0][1] + a[1][b]) : 0;
        for (int c = 0; c < 9; c++) {
          if (c == z || c == b)
            continue;
          num[0][2] = a[0][2] > a[1][c] ? (a[0][2] + a[1][c]) : 0;
          num[1][2] = a[0][2] <= a[1][c] ? (a[0][2] + a[1][c]) : 0;
          for (int d = 0; d < 9; d++) {
            if (d == z || d == b || d == c)
              continue;
            num[0][3] = a[0][3] > a[1][d] ? (a[0][3] + a[1][d]) : 0;
            num[1][3] = a[0][3] <= a[1][d] ? (a[0][3] + a[1][d]) : 0;
            for (int e = 0; e < 9; e++) {
              if (e == z || e == b || e == c || e == d)
                continue;
              num[0][4] = a[0][4] > a[1][e] ? (a[0][4] + a[1][e]) : 0;
              num[1][4] = a[0][4] <= a[1][e] ? (a[0][4] + a[1][e]) : 0;
              for (int f = 0; f < 9; f++) {
                if (f == z || f == b || f == c || f == d || f == e)
                  continue;
                num[0][5] = a[0][5] > a[1][f] ? (a[0][5] + a[1][f]) : 0;
                num[1][5] = a[0][5] <= a[1][f] ? (a[0][5] + a[1][f]) : 0;
                for (int g = 0; g < 9; g++) {
                  if (g == z || g == b || g == c || g == d || g == e || g == f)
                    continue;
                  num[0][6] = a[0][6] > a[1][g] ? (a[0][6] + a[1][g]) : 0;
                  num[1][6] = a[0][6] <= a[1][g] ? (a[0][6] + a[1][g]) : 0;
                  for (int h = 0; h < 9; h++) {
                    if (h == z || h == b || h == c || h == d || h == e ||
                        h == f || h == g)
                      continue;
                    num[0][7] = a[0][7] > a[1][h] ? (a[0][7] + a[1][h]) : 0;
                    num[1][7] = a[0][7] <= a[1][h] ? (a[0][7] + a[1][h]) : 0;
                    for (int i = 0; i < 9; i++) {
                      if (i == z || i == b || i == c || i == d || i == e ||
                          i == f || i == g || i == h)
                        continue;
                      num[0][8] = a[0][8] > a[1][i] ? (a[0][8] + a[1][i]) : 0;
                      num[1][8] = a[0][8] <= a[1][i] ? (a[0][8] + a[1][i]) : 0;
                      int geitu = num[0][0] + num[0][1] + num[0][2] + num[0][3] + num[0][4] + num[0][5] + num[0][6] + num[0][7] + num[0][8];
                      int jacky = num[1][0] + num[1][1] + num[1][2] + num[1][3] + num[1][4] + num[1][5] + num[1][6] + num[1][7] + num[1][8];
                      if (geitu > jacky)
                        winrate1++;
                      else if (geitu < jacky)
                        winrate2++;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    double ans = (winrate1 / 362880 * 100000 + 0.5) / 100000;
    double ans2 = (winrate2 / 362880 * 100000 + 0.5) / 100000;
    cout << ans << " " << ans2 << "\n";
  }
  return 0;
}