#include <iostream>
using namespace std;
int main() {
  int n, m, a;
  while (true) {
    cin >> n >> m >> a;
    if (n == 0 && m == 0 && a == 0) {
      break;
    }
    int amida[2][1001] = {{0}};
    for (int i = 0; i < m; i++) {
      int h, p, q;
      cin >> h >> p >> q;
      amida[p % 2][h] = 1;
    }
    for (int j = 1000; j > 0; j--) {
      if (amida[a % 2][j] == 1)
        a++;
      else if (amida[(a - 1) % 2][j] == 1)
        a--;
    }
    cout << a << endl;
    // Reset the arrays for the next iteration.
    fill_n(amida[0], 1001, 0);
    fill_n(amida[1], 1001, 0);
  }
  return 0;
}