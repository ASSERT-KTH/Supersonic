#include <iostream>
using namespace std;

int main() {
  int x, y, s;
  const double factor = 100.0;
  while (cin >> x >> y >> s && (x || y || s)) {
    int maxi = 0, a = 1, b;
    while (a < s) {
      b = (s - (int)((a * (factor + x)) / factor) + 1) / ((factor + x) / factor);
      if ((int)((a * (factor + x)) / factor) + (int)((b * (factor + x)) / factor) == s) {
        maxi = max(maxi, (int)((a * (factor + y)) / factor + (b * (factor + y)) / factor));
      }
      a++;
    }
    cout << maxi << endl;
  }
  return 0;
}