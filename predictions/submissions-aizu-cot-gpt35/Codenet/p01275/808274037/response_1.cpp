#include <iostream>
using namespace std;

int k, ans;
int dif[12];
const int M = 10;

void rec(int d, int p, int rot) {
  if (p == k) {
    ans = d;
    return;
  }
  if (d >= ans)
    return;
  if (rot == 0) {
    rec(d, p + 1, dif[p + 1]);
    return;
  }
  rec(d + 1, p + 1, dif[p + 1]);
  for (int i = p; i < k; i++) {
    dif[i] = (dif[i] - rot) & (M - 1);
    rec(d + 1, p + 1, dif[p + 1]);
  }
  for (int i = p; i < k; i++)
    dif[i] = (dif[i] + rot + M) & (M - 1);
}

int main() {
  while (cin >> k, k) {
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < k; i++) {
      dif[i] = ((int)(t[i] - s[i]) + M) & (M - 1);
    }
    ans = k;
    rec(0, 0, dif[0]);
    cout << ans << endl;
  }
}