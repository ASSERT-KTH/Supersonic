#include <iostream>
using namespace std;

const int M = 10;

void rec(int d, int p, int k, int dif[]) {
  if (p == k) {
    return;
  }
  if (d >= k) {
    return;
  }
  int rot = dif[p];
  if (rot == 0) {
    rec(d, p + 1, k, dif);
    return;
  }
  rec(d + 1, p + 1, k, dif);
  for (; p < k; p++) {
    dif[p] = (dif[p] + M - rot) % M;
    rec(d + 1, p + 1, k, dif);
    dif[p] = (dif[p] + rot) % M;
  }
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
    rec(0, 0, k, dif);
    cout << k << endl;
  }
}