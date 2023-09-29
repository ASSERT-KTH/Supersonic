#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<pair<int, int>> hwPairs;
  
  while (true) {
    int h, w;
    cin >> h >> w;
    if (h == 0 && w == 0)
      break;
    hwPairs.push_back(make_pair(h, w));
  }

  for (const auto &hw : hwPairs) {
    string row(hw.second, '#');
    for(int i = 0; i < hw.first; ++i) {
      cout << row << '\n';
    }
    cout << '\n';
  }

  return 0;
}