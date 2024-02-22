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
    vector<vector<int>> amida(n+1, vector<int>(m+1, 0));
    for (int i = 0; i < m; i++) {
      int h, p;
      cin >> h >> p;
      amida[p][h] = 1;
    }
    for (int j = m; j > 0; j--) {
      if (amida[a][j] == 1)
        a++;
      else if (a > 1 && amida[a - 1][j] == 1)
        a--;
    }
    cout << a << endl;
  }
  return 0;
}