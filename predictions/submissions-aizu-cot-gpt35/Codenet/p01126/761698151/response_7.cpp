#include <iostream>
using namespace std;

int main() {
  int n, m, a;
  while (true) {
    cin >> n >> m >> a;
    if (n == 0 || m == 0 || a == 0) {
      break;
    }

    int amida[1001] = {0};
    for (int i = 0; i < m; i++) {
      int h, p, q;
      cin >> h >> p >> q;
      amida[h] = p;
    }

    while (a > 0) {
      if (amida[a] != 0)
        a = amida[a];
      else if (amida[a - 1] != 0)
        a = amida[a - 1];
      else
        break;
    }

    cout << a << endl;
  }

  return 0;
}