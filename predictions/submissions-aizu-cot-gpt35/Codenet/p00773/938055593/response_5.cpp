#include <iostream>
#include <vector>
using namespace std;

int main() {
  int x, y, s;
  while (cin >> x >> y >> s && (x || y || s)) {
    vector<vector<int>> tax(s + 1, vector<int>(2));
    int maxTax = 0, index = 0, a = 1, b;
    while (a < s) {
      b = (s - (a * (100 + x)) / 100 + 1) / ((100 + x) / 100);
      if (((a * (100 + x)) / 100 + (b * (100 + x)) / 100) == s && b != 0) {
        tax[index][0] = a;
        tax[index][1] = b;
        maxTax = max(maxTax, (tax[index][0] * (100 + y)) / 100 +
                                 (tax[index][1] * (100 + y)) / 100);
        index++;
      }
      a++;
    }
    cout << maxTax << endl;
  }
  return 0;
}