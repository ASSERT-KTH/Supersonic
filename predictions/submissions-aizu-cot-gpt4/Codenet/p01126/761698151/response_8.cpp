#include <iostream>
using namespace std;

int main() {
  int n, m, a;
  int amida[101][1001] = {{0}};
  while (true) {
    cin >> n >> m >> a;
    if (n == 0 && m == 0 && a == 0) {
      break;
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        amida[i][j] = 0;
      }
    }
    for (int i = 0; i < m; i++) {
      int h = 0, p = 0, q = 0;
      cin >> h >> p >> q;
      amida[p][h] = 1;
    }
    for (int j = m; j > 0; j--) {
      if (amida[a][j] == 1)
        ++a;
      else if (amida[a - 1][j] == 1)
        --a;
    }
    cout << a << endl;
  }
  return 0;
}