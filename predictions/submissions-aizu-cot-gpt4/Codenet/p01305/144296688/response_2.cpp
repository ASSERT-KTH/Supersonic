#include <cstdlib>
#include <iostream>
#include <numeric>
using namespace std;
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
    for (int z = 0; z < 9; z++) {
      for (int b = 0; b < 9; b++) {
        if (b == z)
          continue;
        for (int c = 0; c < 9; c++) {
          if (c == z || c == b)
            continue;
          for (int d = 0; d < 9; d++) {
            if (d == z || d == b || d == c)
              continue;
            for (int e = 0; e < 9; e++) {
              if (e == z || e == b || e == c || e == d)
                continue;
              for (int f = 0; f < 9; f++) {
                if (f == z || f == b || f == c || f == d || f == e)
                  continue;
                for (int g = 0; g < 9; g++) {
                  if (g == z || g == b || g == c || g == d || g == e || g == f)
                    continue;
                  for (int h = 0; h < 9; h++) {
                    if (h == z || h == b || h == c || h == d || h == e ||
                        h == f || h == g)
                      continue;
                    for (int i = 0; i < 9; i++) {
                      if (i == z || i == b || i == c || i == d || i == e ||
                          i == f || i == g || i == h)
                        continue;
                      int geitu = accumulate(num[0], num[0] + 9, 0);
                      int jacky = accumulate(num[1], num[1] + 9, 0);
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
    double ans = winrate1 / 362880;
    double ans2 = winrate2 / 362880;
    cout << ans << " " << ans2 << "\n";
  }
  return 0;
}