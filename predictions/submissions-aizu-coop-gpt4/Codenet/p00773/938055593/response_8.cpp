#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int x, y, s;
  while (cin >> x >> y >> s && (x || y || s)) {
    vector<pair<int, int>> taxPair;
    int maxi = 0, a = 1, b;
    while (a < s) {
      int aTax = (int)((a * (100 + x)) / 100.0);
      b = (s - aTax + 1) / ((100 + x) / 100.0);
      if ((aTax + (int)((b * (100 + x)) / 100.0)) == s && b != 0) {
        taxPair.push_back({a, b});
        maxi = max(maxi, (int)((taxPair.back().first * (100 + y)) / 100.0) +
                             (int)((taxPair.back().second * (100 + y)) / 100.0));
      }
      a++;
    }
    cout << maxi << endl;
  }
  return 0;
}