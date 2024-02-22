#include <iostream>
using namespace std;
int main() {
  int x, y, s;
  while (cin >> x >> y >> s && (x || y || s)) {
    int maxi = 0, a = 1, b;
    while (a < s) {
      int a_tax = a * (1.0 + x / 100.0);
      b = (s - a_tax + 1) / (1.0 + x / 100.0);
      if (a_tax +  b * (1.0 + x / 100.0) == s && b != 0) {
        maxi = max(maxi, (int)(a * (1.0 + y / 100.0)) +
                             (int)(b * (1.0 + y / 100.0)));
      }
      ++a;
    }
    cout << maxi << endl;
  }
  return 0;
}