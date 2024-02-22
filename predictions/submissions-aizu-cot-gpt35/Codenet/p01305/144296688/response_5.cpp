#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int l = 0; l < n; l++) {
    int a[2][9], geitu, jacky;
    double winrate1 = 0, winrate2 = 0;
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 9; k++)
        cin >> a[j][k];
    }

    // Calculate the partial sums for each array
    int partialSum1[9] = {0};
    int partialSum2[9] = {0};
    for (int k = 0; k < 9; k++) {
      if (k > 0) {
        partialSum1[k] = partialSum1[k - 1] + a[0][k];
        partialSum2[k] = partialSum2[k - 1] + a[1][k];
      } else {
        partialSum1[k] = a[0][k];
        partialSum2[k] = a[1][k];
      }
    }

    // Calculate the win rates
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
                    if (h == z || h == b || h == c || h == d || h == e || h == f || h == g)
                      continue;
                    for (int i = 0; i < 9; i++) {
                      if (i == z || i == b || i == c || i == d || i == e || i == f || i == g || i == h)
                        continue;
                      geitu = partialSum1[z] + partialSum1[b] + partialSum1[c] + partialSum1[d] + partialSum1[e] + partialSum1[f] + partialSum1[g] + partialSum1[h] + partialSum1[i];
                      jacky = partialSum2[z] + partialSum2[b] + partialSum2[c] + partialSum2[d] + partialSum2[e] + partialSum2[f] + partialSum2[g] + partialSum2[h] + partialSum2[i];
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