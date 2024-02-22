#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m, a, h, p, q;
  vector<vector<int>> amida(101, vector<int>(1001, 0));

  while (true) {
    cin >> n >> m >> a;
    if (n == 0 && m == 0 && a == 0) {
      break;
    }

    for (int i = 0; i < 101; i++) {
      fill(amida[i].begin(), amida[i].end(), 0);
    }

    for (int i = 0; i < m; i++) {
      cin >> h >> p >> q;
      amida[p][h] = 1;
    }

    for (int j = 1000; j > 0; j--) {
      int current = amida[a][j];
      int previous = amida[a - 1][j];
      if (current == 1)
        a++;
      else if (previous == 1)
        a--;
    }

    cout << a << endl;
  }

  return 0;
}