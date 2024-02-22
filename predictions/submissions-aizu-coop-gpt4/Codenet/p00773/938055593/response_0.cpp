#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int x, y, s;
  while (cin >> x >> y >> s && (x || y || s)) {
    int maxi = 0;
    for (int a = 1; a < s; a++) {
      int b = (s - (int)((a * (100 + x)) / 100.0) + 1) / ((100 + x) / 100.0);
      int sum = (int)((a * (100 + x)) / 100.0) + (int)((b * (100 + x)) / 100.0);
      if (sum == s) {
        maxi = max(maxi, (int)((a * (100 + y)) / 100.0) +
                             (int)((b * (100 + y)) / 100.0));
      }
    }
    cout << maxi << endl;
  }
  return 0;
}