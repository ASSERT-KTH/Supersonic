#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m, a;
  while (true) {
    cin >> n >> m >> a;
    if (n == 0 && m == 0 && a == 0) {
      break;
    }
    vector<vector<int>> amida(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
      int h, p, q;
      cin >> h >> p >> q;
      amida[p][h] = 1;
    }
    for (int j = n; j >= 1; j--) {
      a = amida[a][j] ? a + 1 : a - 1;
    }
    cout << a << endl;
  }
  return 0;
}