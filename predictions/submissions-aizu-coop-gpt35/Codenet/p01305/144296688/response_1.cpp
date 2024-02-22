#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the winrate
void calculateWinrate(int n) {
  for (int l = 0; l < n; l++) {
    // Use vectors instead of fixed-size arrays for dynamic memory allocation
    vector<vector<int>> num(2, vector<int>(9, 0));
    vector<vector<int>> a(2, vector<int>(9, 0));
    double winrate1 = 0, winrate2 = 0;

    // Read input values
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 9; k++)
        cin >> a[j][k];
    }

    // Calculate sums incrementally
    int geitu = 0, jacky = 0;
    for (int z = 0; z < 9; z++) {
      num[0][0] = a[0][0] + a[1][z];
      num[1][0] = a[0][0] + a[1][z];

      for (int b = 0; b < 9; b++) {
        if (b == z)
          continue;
        num[0][1] = a[0][1] + a[1][b];
        num[1][1] = a[0][1] + a[1][b];

        for (int c = 0; c < 9; c++) {
          if (c == z || c == b)
            continue;
          num[0][2] = a[0][2] + a[1][c];
          num[1][2] = a[0][2] + a[1][c];

          for (int d = 0; d < 9; d++) {
            if (d == z || d == b || d == c)
              continue;
            num[0][3] = a[0][3] + a[1][d];
            num[1][3] = a[0][3] + a[1][d];

            for (int e = 0; e < 9; e++) {
              if (e == z || e == b || e == c || e == d)
                continue;
              num[0][4] = a[0][4] + a[1][e];
              num[1][4] = a[0][4] + a[1][e];

              for (int f = 0; f < 9; f++) {
                if (f == z || f == b || f == c || f == d || f == e)
                  continue;
                num[0][5] = a[0][5] + a[1][f];
                num[1][5] = a[0][5] + a[1][f];

                for (int g = 0; g < 9; g++) {
                  if (g == z || g == b || g == c || g == d || g == e || g == f)
                    continue;
                  num[0][6] = a[0][6] + a[1][g];
                  num[1][6] = a[0][6] + a[1][g];

                  for (int h = 0; h < 9; h++) {
                    if (h == z || h == b || h == c || h == d || h == e ||
                        h == f || h == g)
                      continue;
                    num[0][7] = a[0][7] + a[1][h];
                    num[1][7] = a[0][7] + a[1][h];

                    for (int i = 0; i < 9; i++) {
                      if (i == z || i == b || i == c || i == d || i == e ||
                          i == f || i == g || i == h)
                        continue;
                      num[0][8] = a[0][8] + a[1][i];
                      num[1][8] = a[0][8] + a[1][i];

                      // Calculate sums incrementally
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

    // Calculate and print the winrates
    double ans = winrate1 / 362880;
    double ans2 = winrate2 / 362880;
    cout << ans << " " << ans2 << "\n";
  }
}

int main() {
  int n;
  cin >> n;
  calculateWinrate(n);
  return 0;
}