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
    vector<vector<int>> amida(n+1, vector<int>(m+1, 0)); // Dynamic 2D vector
    for (int i = 0; i < m; i++) {
      int h = 0, p = 0, q = 0;
      cin >> h >> p >> q;
      amida[p][h] = 1;
    }
    for (int j = 1; j <= m; j++) { // Traverse from top to bottom
      if (amida[a][j] == 1)
        a++;
      else if (a > 1 && amida[a - 1][j] == 1)
        a--;
    }
    cout << a << endl;
  }
  return 0;
}