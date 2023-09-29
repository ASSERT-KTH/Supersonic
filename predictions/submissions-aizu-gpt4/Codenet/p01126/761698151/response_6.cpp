#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, a;
  while (cin >> n >> m >> a, n | m | a) {
    vector<vector<int>> amida(n + 1, vector<int>(1001, 0));
    while (m--) {
      int h, p, q;
      cin >> h >> p >> q;
      amida[p][h] = 1;
    }
    for (int j = 1000; j > 0; --j) {
      if (amida[a][j] == 1)
        ++a;
      else if (a > 1 && amida[a - 1][j] == 1)
        --a;
    }
    cout << a << "\n";
  }
  return 0;
}