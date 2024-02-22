#include <iostream>
using namespace std;

int main() {
  int n, m, a, h, p, q;
  int max_h;
  int amida[101][1001] = {{0}};
  while (true) {
    cin >> n >> m >> a;
    if (n == 0 && m == 0 && a == 0) {
      break;
    }
    max_h = 0;
    for (int i = 0; i < m; i++) {
      cin >> h >> p >> q;
      max_h = max(max_h, h);
      amida[p][h] = 1;
    }
    for (int j = max_h; j > 0; j--) {
      int current = amida[a][j];
      int previous = amida[a - 1][j];
      if (current == 1)
        a++;
      else if (previous == 1)
        a--;
      if (j == max_h) {
        fill(amida[p], amida[p] + max_h + 1, 0);
        fill(amida[p+1], amida[p+1] + max_h + 1, 0);
      }
    }
    cout << a << endl;
  }
  return 0;
}