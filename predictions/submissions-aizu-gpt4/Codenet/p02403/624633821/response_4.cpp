#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<pair<int, int>> dimensions;
  int h, w;

  while ((cin >> h >> w) && (h != 0 && w != 0)) {
    dimensions.emplace_back(h, w);
  }

  for (const auto &dimension : dimensions) {
    string row(dimension.second, '#');
    for (int i = 0; i < dimension.first; ++i) {
      cout << row << "\n";
    }
    cout << "\n";
  }

  return 0;
}