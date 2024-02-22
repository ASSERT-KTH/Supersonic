#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int x, y, s;
  while (cin >> x >> y >> s && (x || y || s)) {
    vector<pair<int, int>> tax;
    int maxi = 0, a = 1, b, a_tax;
    while (a < s) {
      a_tax = (int)((a * (100 + x)) / 100.0);
      b = (s - a_tax + 1) / ((100 + x) / 100.0);
      if (a_tax + (int)((b * (100 + x)) / 100.0) == s && b != 0) {
        tax.push_back({a, b});
        maxi = max(maxi, (int)((a * (100 + y)) / 100.0) +
                             (int)((b * (100 + y)) / 100.0));
      }
      a++;
    }
    cout << maxi << endl;
  }
  return 0;
}