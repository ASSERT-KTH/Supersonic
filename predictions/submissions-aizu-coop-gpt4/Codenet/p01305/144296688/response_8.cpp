#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <numeric>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int l = 0; l < n; l++) {
    int a[2][9];
    double winrate1 = 0, winrate2 = 0;
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 9; k++)
        cin >> a[j][k];
      sort(a[j], a[j] + 9);  // Sort the arrays to enable permutation generation
    }
    do {
      int geitu = 0, jacky = 0;
      for (int i = 0; i < 9; i++) {  // Iterate through all games
        if (a[0][i] > a[1][i])
          geitu += a[0][i] + a[1][i];  // Update the total scores incrementally
        else
          jacky += a[0][i] + a[1][i];
      }
      if (geitu > jacky)
        winrate1++;
      else if (geitu < jacky)
        winrate2++;
    } while (next_permutation(a[1], a[1] + 9));  // Generate the next permutation
    double ans = round(winrate1 / 362880 * 1e5) / 1e5;
    double ans2 = round(winrate2 / 362880 * 1e5) / 1e5;
    cout << ans << " " << ans2 << "\n";
  }
  return 0;
}