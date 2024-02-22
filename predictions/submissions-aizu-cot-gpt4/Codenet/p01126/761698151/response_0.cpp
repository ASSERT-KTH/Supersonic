#include <iostream>
#include <map>
#include <utility>
using namespace std;

int main() {
  int m, a;
  while (true) {
    cin >> m >> a;
    if (m == 0 && a == 0) {
      break;
    }
    map<pair<int, int>, int> amida;
    int max_h = 0;
    for (int i = 0; i < m; i++) {
      int h, p;
      cin >> h >> p;
      amida[{p, h}] = 1;
      if (h > max_h) max_h = h;
    }
    for (int j = max_h; j > 0; j--) {
      if (amida[{a, j}] == 1)
        a++;
      else if (amida[{a - 1, j}] == 1)
        a--;
    }
    cout << a << endl;
  }
  return 0;
}