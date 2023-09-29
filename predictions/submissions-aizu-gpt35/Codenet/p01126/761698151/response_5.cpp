#include <iostream>
using namespace std;
int main() {
  int n, m, a;
  while (true) {
    cin >> n >> m >> a;
    if (n == 0 && m == 0 && a == 0) {
      break;
    }
    bool amida[101][1001] = {false};
    for (int i = 0; i < m; i++) {
      int h = 0, p = 0, q = 0;
      cin >> h >> p >> q;
      amida[p][h] = true;
    }
    for (int j = 1000; j > 0; j--) {
      if (amida[a][j])
        a++;
      else if (amida[a - 1][j])
        a--;
    }
    cout << a << endl;
  }
  return 0;
}