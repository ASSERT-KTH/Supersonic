#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int x, y, s;
  while (cin >> x >> y >> s && (x || y || s)) {
    int maxi = 0, a = 1, b, a_val, b_val;
    double tax_rate = 1.0 / ((100 + x) / 100.0);
    while (a < s) {
      b = (s - (int)(a * tax_rate) + 1) * tax_rate;
      a_val = (int)(a * tax_rate);
      b_val = (int)(b * tax_rate);
      if (a_val + b_val == s && b != 0) {
        maxi = max(maxi, (int)((a * (100 + y)) / 100.0) + (int)((b * (100 + y)) / 100.0));
      }
      a++;
    }
    cout << maxi << endl;
  }
  return 0;
}