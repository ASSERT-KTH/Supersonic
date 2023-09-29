#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<pair<int, int>> HW;
  int h, w;
  while (cin >> h >> w, h || w) {
    HW.emplace_back(h, w);
  }
  for (const auto& hw : HW) {
    string line(hw.second, '#');
    for (int i = 0; i < hw.first; i++) {
      cout << line << '\n';
    }
    cout << '\n';
  }
  return 0;
}