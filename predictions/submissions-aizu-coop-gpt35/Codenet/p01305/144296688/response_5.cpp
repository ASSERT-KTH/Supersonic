#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int l = 0; l < n; l++) {
    int a[9], num[9], geitu = 0, jacky = 0;
    double winrate1 = 0, winrate2 = 0;

    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 9; k++)
        cin >> a[k];
    }

    for (int mask = 0; mask < 362880; mask++) {
      for (int i = 0; i < 9; i++) {
        num[i] = a[i];
        if ((1 << i) & mask) {
          num[i] += a[9 + i];
        }
      }

      geitu = 0;
      jacky = 0;
      for (int m = 0; m < 9; m++) {
        geitu += num[m];
        jacky += num[9 + m];
      }

      if (geitu > jacky)
        winrate1++;
      else if (geitu < jacky)
        winrate2++;
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