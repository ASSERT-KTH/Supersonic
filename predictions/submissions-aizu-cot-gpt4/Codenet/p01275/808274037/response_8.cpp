#include <iostream>
using namespace std;
int k, ans;
int dif[12];
const int M = 10;
void rec(int d, int p) {
  if (p == k) {
    ans = d;
    return;
  }
  if (d >= ans)
    return;
  int rot = dif[p];
  if (rot == 0) {
    rec(d, p + 1);
    return;
  }
  int newRot = (dif[p] - rot + M) % M; // compute once
  for (int i = p; i < k; i++) {
    dif[i] = newRot;
  }
  rec(d + 1, p + 1);
  for (int i = p; i < k; i++)
    dif[i] = (dif[i] + rot) % M;
}
int main() {
  while (cin >> k, k) {
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < k; i++) {
      dif[i] = ((int)(t[i] - s[i]) + M) % M;
    }
    ans = k;
    rec(0, 0);
    cout << ans << endl;
  }
}