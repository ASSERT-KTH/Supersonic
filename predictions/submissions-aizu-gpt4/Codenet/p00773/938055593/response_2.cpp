#include <iostream>
using namespace std;
int main() {
  int x, y, s;
  while (cin >> x >> y >> s && (x || y || s)) {
    int maxi = 0;
    for(int a = 1; a < s; ++a) {
      int b = (s - a * (100 + x) / 100) * 100 / (100 + x);
      if (a * (100 + x) / 100 + b * (100 + x) / 100 == s) {
        maxi = max(maxi, a * (100 + y) / 100 + b * (100 + y) / 100);
      }
    }
    cout << maxi << endl;
  }
  return 0;
}