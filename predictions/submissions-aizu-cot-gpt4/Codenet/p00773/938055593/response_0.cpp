#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int x, y, s;
  while (cin >> x >> y >> s && (x || y || s)) {
    vector<vector<int>> tax;
    int maxi = 0, a = 1, b;
    while (a < s) {
      int a_tax = (int)((a * (100 + x)) / 100.0);
      b = (s - a_tax + 1) / ((100 + x) / 100.0);
      int b_tax = (int)((b * (100 + x)) / 100.0);
      if ((a_tax + b_tax) == s && b != 0) {
        vector<int> temp = {a, b};
        tax.push_back(temp);
        int a_tax_y = (int)((a * (100 + y)) / 100.0);
        int b_tax_y = (int)((b * (100 + y)) / 100.0);
        maxi = max(maxi, a_tax_y + b_tax_y);
      }
      a++;
    }
    cout << maxi << endl;
  }
  return 0;
}