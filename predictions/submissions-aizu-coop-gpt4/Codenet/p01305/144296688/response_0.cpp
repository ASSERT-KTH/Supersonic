#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> a[2];
  vector<int> num[2], idx(9);
  int geitu, jacky;
  double winrate1, winrate2;

  for (int l = 0; l < n; l++) {
    winrate1 = 0, winrate2 = 0;
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 9; k++) {
        int temp;
        cin >> temp;
        a[j].push_back(temp);
      }
    }
    
    iota(idx.begin(), idx.end(), 0);

    do {
      num[0].clear();
      num[1].clear();
      for (int m = 0; m < 9; m++) {
        if (a[0][m] > a[1][idx[m]])
          num[0].push_back(a[0][m] + a[1][idx[m]]);
        else
          num[1].push_back(a[0][m] + a[1][idx[m]]);
      }
      geitu = accumulate(num[0].begin(), num[0].end(), 0);
      jacky = accumulate(num[1].begin(), num[1].end(), 0);
      if (geitu > jacky)
        winrate1++;
      else if (geitu < jacky)
        winrate2++;
    } while (next_permutation(idx.begin(), idx.end()));

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