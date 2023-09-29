#include <iostream>
#include <algorithm>
using namespace std;
int k, ans;
int dif[12];

const int M = 10;

void rec(int d, int p, int dif[]) {
  if (p == k) {
    ans = min(ans, d);
    return;
  }
  if (d >= ans)
    return;
  int rot = dif[p];
  if (rot == 0) {
    rec(d, p + 1, dif);
    return;
  }
  rec(d + 1, p + 1, dif);
  int difCopy[k];
  copy(dif, dif + k, difCopy);
  for (int i = p; i < k; i++) {
    difCopy[i] = (difCopy[i] - rot + M) % M;
    rec(d + 1, p + 1, difCopy);
  }
}

int main() {
  while (cin >> k, k) {
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < k; i++) {
      dif[i] = ((int)(t[i] - s[i]) + M) % M;
    }
    ans = k;
    rec(0, 0, dif);
    cout << ans << endl;
  }
}