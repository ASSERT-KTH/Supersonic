#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int x, y, s;
  while (cin >> x >> y >> s && (x || y || s)) {
    vector<vector<int>> tax(1000, vector<int>(2));
    int maxi = 0, i = 0;
    for (int a = 1; a < s; a++) {
      int b = (s - (a * (100 + x) + 99) / 100) * 100 / (100 + x);
      if (a * (100 + x) / 100 + b * (100 + x) / 100 == s && b != 0) {
        tax[i][0] = a;
        tax[i][1] = b;
        maxi = max(maxi, tax[i][0] * (100 + y) / 100 + tax[i][1] * (100 + y) / 100);
        i++;
      }
    }
    cout << maxi << "\n";
  }
  return 0;
}