#include <iostream>
using namespace std;

int k, ans;

void rec(int d, int p, int diff) {
  if (p == k) {
    ans = d;
    return;
  }
  if (d >= ans)
    return;
  int rot = diff;
  if (rot == 0) {
    rec(d, p + 1, diff);
    return;
  }
  rec(d + 1, p + 1, diff);
  for (int i = p; i < k - 1; i++) {
    diff = (diff - rot) % 10;
    rec(d + 1, p + 1, diff);
  }
  diff = (diff + rot + 10) % 10;
}

int main() {
  while (cin >> k, k) {
    string s, t;
    cin >> s >> t;
    int diff = 0;
    for (int i = 0; i < k; i++) {
      diff = ((int)(t[i] - s[i]) + 10) % 10;
      rec(0, 0, diff);
    }
    cout << ans << endl;
  }
}