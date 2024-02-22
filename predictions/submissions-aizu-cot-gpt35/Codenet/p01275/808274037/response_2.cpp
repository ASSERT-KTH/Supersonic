#include <iostream>
using namespace std;

int main() {
  int k;
  while (cin >> k, k) {
    string s, t;
    cin >> s >> t;

    int ans = k;
    int dif[12];
    const int M = 10;

    for (int i = 0; i < k; i++) {
      dif[i] = ((int)(t[i] - s[i]) + M) % M;
    }

    int p = 0;
    int d = 0;
    while (p < k) {
      if (d >= ans) {
        break;
      }

      int rot = dif[p];
      if (rot == 0) {
        p++;
        continue;
      }

      int numRotations = (ans - d - 1) / (k - p) + 1;
      d += numRotations;

      for (int i = p; i < k; i++) {
        dif[i] = (dif[i] - rot + M) % M;
      }

      p++;
    }

    cout << ans << endl;
  }
}