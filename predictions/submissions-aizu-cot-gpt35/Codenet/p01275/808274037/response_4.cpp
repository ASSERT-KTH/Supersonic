#include <iostream>
using namespace std;

const int M = 10;

void rec(int d, int p, int& ans, int dif[]) {
  if (p == k) {
    ans = d;
    return;
  }
  if (d >= ans)
    return;
  int rot = dif[p];
  if (rot == 0) {
    rec(d, p + 1, ans, dif);
    return;
  }
  rec(d + 1, p + 1, ans, dif);
  dif[p] = (dif[p] - rot) % M;
  rec(d + 1, p + 1, ans, dif);
  dif[p] = (dif[p] + rot + M) % M;
}

int main() {
  int k;
  while (cin >> k, k) {
    string s, t;
    cin >> s >> t;
    int dif[k];
    for (int i = 0; i < k; i++) {
      dif[i] = ((int)(t[i] - s[i]) + M) % M;
    }
    int ans = k;
    rec(0, 0, ans, dif);
    cout << ans << endl;
  }
}