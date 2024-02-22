#include <iostream>
#include <vector>
using namespace std;

int main() {
  int x, y, s;
  while (cin >> x >> y >> s && (x || y || s)) {
    vector<vector<int>> tax(1, vector<int>(2));
    int maxi = 0, i = 0, a = 1, b;
    while (a <= s / 2) {
      b = (s - a * (100 + x) / 100) * 100 / (100 + x);
      if (a * (100 + x) + b * (100 + x) == s * 100 && b != 0) {
        if (i >= tax.size()) {
          tax.push_back(vector<int>(2));
        }
        tax[i][0] = a;
        tax[i][1] = b;
        maxi = max(maxi, tax[i][0] * (100 + y) + tax[i][1] * (100 + y));
        i++;
      }
      a++;
    }
    cout << maxi << endl;
  }
  return 0;
}