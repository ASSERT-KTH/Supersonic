#include <iostream>
using namespace std;

int main() {
  int n, m, a;
  while (true) {
    cin >> n >> m >> a;
    if (n == 0 && m == 0 && a == 0) {
      break;
    }
    int amida[1001] = {0};
    int next_rung[1001] = {0};
    for (int i = 0; i < m; i++) {
      int h = 0, p = 0, q = 0;
      cin >> h >> p >> q;
      amida[h] = 1;
      next_rung[h] = q;
    }
    while (n > 0) {
      if (amida[n] == 1)
        n = next_rung[n];
      else
        n--;
    }
    cout << n << endl;
  }
  return 0;
}