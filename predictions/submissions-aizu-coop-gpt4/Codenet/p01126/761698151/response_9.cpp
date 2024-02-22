#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  int n, m, a;
  while (true) {
    cin >> n >> m >> a;
    if (n == 0 && m == 0 && a == 0) {
      break;
    }
    vector<pair<int, int>> amida;
    for (int i = 0; i < m; i++) {
      int h = 0, p = 0, q = 0;
      cin >> h >> p >> q;
      amida.push_back({p, h});
    }
    sort(amida.begin(), amida.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
      return a.second > b.second;
    });
    for (const auto& [p, h] : amida) {
      if (p == a)
        a++;
      else if (p == a - 1)
        a--;
    }
    cout << a << endl;
  }
  return 0;
}