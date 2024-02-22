#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int l = 0; l < n; l++) {
    int a[2][9];
    double winrate1 = 0, winrate2 = 0;

    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 9; k++)
        cin >> a[j][k];

    sort(a[1], a[1] + 9);
    do {
      int geitu = 0, jacky = 0;
      for (int z = 0; z < 9; z++) {
        if (a[0][z] > a[1][z])
          geitu += a[0][z] + a[1][z];
        else
          jacky += a[0][z] + a[1][z];
      }
      if (geitu > jacky)
        winrate1++;
      else if (geitu < jacky)
        winrate2++;
    } while (next_permutation(a[1], a[1] + 9));

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