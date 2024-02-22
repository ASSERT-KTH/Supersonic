#include <iostream>
#include <map>
using namespace std;

int main() {
  map<int, map<int, int>> amida;
  int n, m, a;
  while (cin >> n >> m >> a) {
    if (n == 0 && m == 0 && a == 0) {
      break;
    }
    amida.clear();
    for (int i = 0; i < m; i++) {
      int h = 0, p = 0, q = 0;
      cin >> h >> p >> q;
      amida[p][h] = 1;
    }
    for (int j = 1000; j > 0; j--) {
      if (amida[a][j] == 1)
        a++;
      else if (amida[a - 1][j] == 1)
        a--;
    }
    cout << a << endl;
  }
  return 0;
}