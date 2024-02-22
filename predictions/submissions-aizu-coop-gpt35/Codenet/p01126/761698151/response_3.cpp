#include <iostream>
using namespace std;

int main() {
  int n, m, a;
  while (true) {
    cin >> n >> m >> a;
    if (n == 0 && m == 0 && a == 0) {
      break;
    }
    int amida[101] = {0};
    for (int i = 0; i < m; i++) {
      int h = 0, p = 0, q = 0;
      cin >> h >> p >> q;
      amida[p] = q;
    }
    for (int j = 1; j <= m; j++) {
      if (amida[a] == j)
        a = j;
      else if (amida[a - 1] == j)
        a = j - 1;
    }
    cout << a << endl;
  }
  return 0;
}