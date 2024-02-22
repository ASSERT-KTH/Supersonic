#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  int m, a;
  pair<int, int> p;
  while (true) {
    cin >> m >> a;
    if (m == 0 && a == 0) {
      continue;
    }

    unordered_map<int, unordered_map<int, int>> amida;

    for (int i = 0; i < m; i++) {
      int h, p, q;
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