#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;

int main() {
  int n, m, l, k, a, h, t1, t2, t3;
  while (cin >> n >> m >> l >> k >> a >> h, n) {
    vector<int> rei(l);
    rei[0] = a;
    rei[1] = h;
    for (int i = 2; i < l; i++) {
      cin >> rei[i];
    }

    int b[l][l], x[l][l];
    for (int i = 0; i < l; i++) {
      for (int j = 0; j < l; j++) {
        x[i][j] = b[i][j] = INF;
      }
    }

    for (int i = 0; i < k; i++) {
      cin >> t1 >> t2 >> t3;
      b[t1][t2] = b[t2][t1] = t3;
    }

    for (int o = 0; o < l; o++) {
      for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
          b[i][j] = min(b[i][j], b[i][o] + b[o][j]);
          x[i][j] = min(x[i][j], x[i][o] + x[o][j]);
        }
      }
    }

    if (x[0][1] >= INF)
      cout << "Help!" << endl;
    else if (x[0][1] < m)
      cout << x[0][1] << endl;
    else
      cout << x[0][1] * 2 - m << endl;
  }
}