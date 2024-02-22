#include <iostream>
using namespace std;

int main() {
  int n, m, a;
  cin >> n >> m >> a;

  while (n != 0 || m != 0 || a != 0) {
    int max_m = 0;
    for (int i = 0; i < m; i++) {
      int h, p, q;
      cin >> h >> p >> q;
      if (p > max_m) {
        max_m = p;
      }
    }

    int amida[max_m + 1][1001] = {{0}};

    for (int i = 0; i < m; i++) {
      int h, p, q;
      cin >> h >> p >> q;
      amida[p][h] = 1;
    }

    for (int j = 1000; j > 0; j--) {
      if (amida[a][j] == 1) {
        a++;
        break;
      } else if (amida[a - 1][j] == 1) {
        a--;
        break;
      }
    }

    cout << a << endl;

    cin >> n >> m >> a;
  }

  return 0;
}