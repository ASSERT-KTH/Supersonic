#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int x, y, s;
  while (cin >> x >> y >> s && (x || y || s)) {
    vector<pair<int, int>> tax;
    for (int i = 1; i <= s / 2; ++i) {
      int j = s - i;
      if (i % 100 != x % 100 && j % 100 != x % 100) continue;
      if ((i / 100 + j / 100) * 100 == s) {
        tax.emplace_back(i / 100, j / 100);
      }
    }
    int maxi = 0;
    for (auto& [a, b] : tax) {
      maxi = max(maxi, a * (100 + y) + b * (100 + y));
    }
    cout << maxi << '\n';
  }
  return 0;
}