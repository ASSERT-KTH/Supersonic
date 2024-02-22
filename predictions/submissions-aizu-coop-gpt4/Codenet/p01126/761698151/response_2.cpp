#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m, a;
  vector<vector<int>> amida(101, vector<int>(1001, 0));
  vector<pair<int, int>> changed;

  while (true) {
    cin >> n >> m >> a;
    if (n == 0 && m == 0 && a == 0) {
      break;
    }

    for (int i = 0; i < m; i++) {
      int h = 0, p = 0;
      cin >> h >> p;
      amida[p][h] = 1;
      changed.push_back({p, h});
    }

    for (int j = 1000; j > 0; --j) {
      if (amida[a][j] == 1)
        ++a;
      else if (a > 1 && amida[a - 1][j] == 1)
        --a;
    }

    cout << a << endl;

    // Reset only the changed elements
    for (auto &p : changed)
      amida[p.first][p.second] = 0;
    changed.clear();
  }

  return 0;
}