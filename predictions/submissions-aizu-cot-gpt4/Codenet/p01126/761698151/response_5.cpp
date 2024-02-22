#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, m, a, h, p, q;
  while (true) {
    cin >> n >> m >> a;
    if (n == 0 && m == 0 && a == 0) {
      break;
    }
    vector<vector<int>> amida(n+1, vector<int>(m+1, 0));
    for (int i = 0; i < m; i++) {
      cin >> h >> p >> q;
      amida[p][h] = 1;
    }
    for (int j = m; j > 0; j--) {
      if (amida[a][j] == 1)
        a++;
      else if (amida[a - 1][j] == 1)
        a--;
    }
    cout << a << '\n';
  }
  return 0;
}