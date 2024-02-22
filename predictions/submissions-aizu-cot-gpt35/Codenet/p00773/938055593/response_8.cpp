#include <iostream>
#include <vector>
using namespace std;

int main() {
  int x, y, s;
  while (cin >> x >> y >> s && (x || y || s)) {
    vector<vector<int>> tax(1000, vector<int>(2));
    int maxi = 0, i = 0, a = 1, b;

    double xFactor = (100 + x) / 100.0;
    double yFactor = (100 + y) / 100.0;

    while (a < s) {
      double aX = a * xFactor;
      double aY = a * yFactor;

      b = (s - (int)aX + 1) / xFactor;

      if ((int)(aX + b * xFactor) == s && b != 0) {
        tax[i][0] = a;
        tax[i][1] = b;
        maxi = max(maxi, (int)(tax[i][0] * yFactor) + (int)(tax[i][1] * yFactor));
        i++;
      }
      a++;
    }
    tax.resize(i);
    cout << maxi << endl;
  }
  return 0;
}