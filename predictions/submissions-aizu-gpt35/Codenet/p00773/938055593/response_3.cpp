#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int x, y, s;
  int a, b, maxi;
  while (cin >> x >> y >> s && (x || y || s)) {
    maxi = 0;
    for (a = 1; a <= s; a++) {
      if ((s - a) % (100 + x) == 0) {
        b = (s - a) / (100 + x);
        maxi = max(maxi, (int)((a * (100 + y)) / 100.0) +
                             (int)((b * (100 + y)) / 100.0));
      }
    }
    cout << maxi << endl;
  }
  return 0;
}