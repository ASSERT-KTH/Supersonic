#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int x, y, s;
  while (cin >> x >> y >> s && (x || y || s)) {
    int maxi = 0, a = 1, b;
    while (a < s) {
      double ax = (a * (100 + x)) / 100.0;
      double bx = (s - (int)ax + 1) / ((100 + x) / 100.0);
      if (((int)ax + (int)bx) == s && b != 0) {
        maxi = max(maxi, (int)((a * (100 + y)) / 100.0) + (int)((b * (100 + y)) / 100.0));
      }
      a++;
    }
    cout << maxi << endl;
  }
  return 0;
}