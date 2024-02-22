#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int x, y, s;
  while (cin >> x >> y >> s && (x || y || s)) {
    int maxi = 0, a = 1, b;
    double rateX = (100 + x) / 100.0;
    double rateY = (100 + y) / 100.0;
    while (a < s) {
      b = (s - static_cast<int>(a * rateX) + 1) / rateX;
      if ((static_cast<int>(a * rateX) + static_cast<int>(b * rateX)) == s) {
        maxi = max(maxi, static_cast<int>(a * rateY) +
                             static_cast<int>(b * rateY));
      }
      a++;
    }
    cout << maxi << endl;
  }
  return 0;
}