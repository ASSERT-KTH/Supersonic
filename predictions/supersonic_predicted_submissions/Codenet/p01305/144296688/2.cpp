#include <cstdlib>
#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int l = 0; l < n; l++) {
    int num[2][9], a[2][9], geitu, jacky;
    double winrate1 = 0;
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 9; k++)
        cin >> a[j][k];
    }
    for (int z = 0; z < 9; z++) {
      num[0][0] = 0;
      num[1][0] = 0;
      if (a[0][0] > a[1][z])
        num[0][0] = (a[0][0] + a[1][z]);
      else
        num[1][0] = (a[0][0] + a[1][z]);
      for (int b = 0; b < 9; b++) {
        if (b == z)
          continue;
        num[0][1] = 0;
        num[1][1] = 0;
        if (a[0][1] > a[1][b])
          num[0][1] = (a[0][1] + a[1][b]);
        else
          num[1][1] = (a[0][1] + a[1][b]);
        for (int c = 0; c < 9; c++) {
          if (c == z || c == b)
            continue;
          num[0][2] = 0;
          num[1][2] = 0;
          if (a[0][2] > a[1][c])
            num[0][2] = (a[0][2] + a[1][c]);
          else
            num[1][2] = (a[0][2] + a[1][c]);
          for (int d = 0; d < 9; d++) {
            if (d == z || d == b || d == c)
              continue;
            num[0][3] = 0;
            num[1][3] = 0;
            if (a[0][3] > a[1][d])
              num[0][3] = (a[0][3] + a[1][d]);
            else
              num[1][3] = (a[0][3] + a[1][d]);
            for (int e = 0; e < 9; e++) {
              if (e == z || e == b || e == c || e == d)
                continue;
              num[0][4] = 0;
              num[1][4] = 0;
              if (a[0][4] > a[1][e])
                num[0][4] = (a[0][4] + a[1][e]);
              else
                num[1][4] = (a[0][4] + a[1][e]);
              for (int f = 0; f < 9; f++) {
                if (f == z || f == b || f == c || f == d || f == e)
                  continue;
                num[0][5] = 0;
                num[1][5] = 0;
                if (a[0][5] > a[1][f])
                  num[0][5] = (a[0][5] + a[1][f]);
                else
                  num[1][5] = (a[0][5] + a[1][f]);
                for (int g = 0; g < 9; g++) {
                  if (g == z || g == b || g == c || g == d || g == e || g == f)
                    continue;
                  num[0][6] = 0;
                  num[1][6] = 0;
                  if (a[0][6] > a[1][g])
                    num[0][6] = (a[0][6] + a[1][g]);
                  else
                    num[1][6] = (a[0][6] + a[1][g]);
                  for (int h = 0; h < 9; h++) {
                    if (h == z || h == b || h == c || h == d || h == e ||
                        h == f || h == g)
                      continue;
                    num[0][7] = 0;
                    num[1][7] = 0;
                    if (a[0][7] > a[1][h])
                      num[0][7] = (a[0][7] + a[1][h]);
                    else
                      num[1][7] = (a[0][7] + a[1][h]);
                    for (int i = 0; i < 9; i++) {
                      if (i == z || i == b || i == c || i == d || i == e ||
                          i == f || i == g || i == h)
                        continue;
                      num[0][8] = 0;
                      num[1][8] = 0;
                      if (a[0][8] > a[1][i])
                        num[0][8] = (a[0][8] + a[1][i]);
                      else
                        num[1][8] = (a[0][8] + a[1][i]);
                      geitu = 0;
                      jacky = 0;
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
                }
              }
            }
          }
        }
      }
    }
    double ans, ans2;
    ans = winrate1 / 362880;
    ans *= 100000;
    ans += 0.5;
    ans = int(ans);
    ans /= 100000;
    ans2 = winrate2 / 362880;
    ans2 *= 100000;
    ans2 += 0.5;
    ans2 = int(ans2);
    ans2 /= 100000;
    cout << ans << " " << ans2 << "\n";
  }
  return 0;
}
