#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, m, a;
  while (cin >> n >> m >> a, n || m || a) {
    vector<vector<int>> amida(n+1, vector<int>(m+1, 0));
    for (int i = 0; i < m; i++) {
      int h = 0, p = 0, q = 0;
      cin >> h >> p >> q;
      amida[p][h] = 1;
    }
    for (int j = m; j > 0; j--) {
      if (amida[a][j] == 1)
        a++;
      else if (a > 1 && amida[a - 1][j] == 1)
        a--;
    }
    cout << a << '\n';
  }
  return 0;
}