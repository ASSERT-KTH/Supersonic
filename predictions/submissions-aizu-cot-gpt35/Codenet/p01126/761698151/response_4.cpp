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
    vector<vector<bool>> amida(n + 1, vector<bool>(m + 1, false));
    for (int i = 0; i < m; i++) {
      int h = 0, p = 0, q = 0;
      cin >> h >> p >> q;
      amida[p][h] = true;
    }
    for (int j = a; j >= 1; j--) {
      if (amida[a][j])
        a++;
      else if (amida[a - 1][j])
        a--;
    }
    cout << a << endl;
  }
  return 0;
}