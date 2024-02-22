#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<vector<int>> a(2, vector<int>(9));
  vector<int> num(2);

  for (int l = 0; l < n; l++) {
    double winrate1 = 0, winrate2 = 0;

    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 9; k++)
        cin >> a[j][k];

    vector<int> indices(9);
    iota(indices.begin(), indices.end(), 0);

    do {
      fill(num.begin(), num.end(), 0);
      int geitu = 0, jacky = 0;

      for (int m = 0; m < 9; m++) {
        if (a[0][m] > a[1][indices[m]])
          num[0] = a[0][m] + a[1][indices[m]];
        else
          num[1] = a[0][m] + a[1][indices[m]];
        
        geitu += num[0];
        jacky += num[1];
      }

      if (geitu > jacky)
        winrate1++;
      else if (geitu < jacky)
        winrate2++;
    } while (next_permutation(indices.begin(), indices.end()));

    cout << winrate1 / 362880 << " " << winrate2 / 362880 << "\n";
  }
  return 0;
}