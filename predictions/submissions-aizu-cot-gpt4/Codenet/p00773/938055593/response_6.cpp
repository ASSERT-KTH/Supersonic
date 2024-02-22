#include <iostream>
using namespace std;

int main() {
  int x, y, s;
  while (cin >> x >> y >> s && (x || y || s)) {
    int maxi = 0, a = 1, b;
    double factor = (100 + x) / 100.0;
    while (a < s) {
      b = (s - (int)(a * factor) + 1) / factor;
      int aVal = (int)(a * factor);
      int bVal = (int)(b * factor);
      if (aVal + bVal == s) {
        int aTax = (int)(a * (100 + y) / 100.0);
        int bTax = (int)(b * (100 + y) / 100.0);
        maxi = max(maxi, aTax + bTax);
      }
      ++a;
    }
    cout << maxi << endl;
  }
  return 0;
}