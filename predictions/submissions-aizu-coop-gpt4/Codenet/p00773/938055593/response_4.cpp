#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int x, y, s;
  while (cin >> x >> y >> s && (x || y || s)) {
    int maxi = 0, a = 1, b;
    while (a < s) {
      double a_tax = (a * (100 + x)) / 100.0;
      b = (s - (int)a_tax + 1) / ((100 + x) / 100.0);
      if ((int)a_tax + (int)((b * (100 + x)) / 100.0) == s && b != 0) {
        maxi = max(maxi, (int)(a_tax * (100 + y) / 100.0) +
                             (int)((b * (100 + y)) / 100.0));
      }
      a++;
    }
    cout << maxi << endl;
  }
  return 0;
}