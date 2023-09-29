#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int x, y, s;
  while (cin >> x >> y >> s && (x || y || s)) {
    vector<vector<int>> tax(1000, vector<int>(2));
    int maxi = 0, i = 0, b;
    while (a < s) {
      b = (s - (int)((a * (100 + x)) / 100.0) + 1) / ((100 + x) / 100.0);
      if (((int)((a * (100 + x)) / 100.0) + (int)((b * (100 + x)) / 100.0)) ==
              s &&
          b != 0) {
        tax[i][0] = a;
        tax[i][1] = b;
        maxi = max(maxi, (int)((tax[i][0] * (100 + y)) / 100.0) +
                           (int)((tax[i][1] * (100 + y)) / 100.0));
        i++;
      }
      a++;
    }
    cout << maxi << endl;
  }
  return 0;
}
