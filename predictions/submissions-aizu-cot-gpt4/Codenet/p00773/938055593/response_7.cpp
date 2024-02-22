#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int x, y, s;
  while (cin >> x >> y >> s && (x || y || s)) {
    int maxi = 0, a = 1, b, calc;
    float y_val = (100 + y) / 100.0, x_val = (100 + x) / 100.0;
    while (a < s) {
      b = (s - (int)(a * x_val) + 1) / x_val;
      calc = (int)(a * x_val) + (int)(b * x_val);
      if (calc == s) {
        maxi = max(maxi, (int)(a * y_val) + (int)(b * y_val));
      }
      a++;
    }
    cout << maxi << endl;
  }
  return 0;
}