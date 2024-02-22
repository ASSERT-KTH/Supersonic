#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int x, y, s;
  while (cin >> x >> y >> s && (x || y || s)) {
    int maxi = 0, a = 1, b;
    double scale = (100 + x) / 100.0;
    double inverse_scale = 1.0 / scale;

    while (a < s) {
      b = (s - (int)(a * scale) + 1) * inverse_scale;
      if ((int)(a * scale) + (int)(b * scale) == s && b != 0) {
        maxi = max(maxi, (int)(a * (100 + y) / 100.0) +
                             (int)(b * (100 + y) / 100.0));
      }
      a++;
    }
    cout << maxi << endl;
  }
  return 0;
}