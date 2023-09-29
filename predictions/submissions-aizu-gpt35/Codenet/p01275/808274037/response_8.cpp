#include <iostream>
#include <cstring>
using namespace std;
const int MAXK = 12;
int k, ans;
int dif[MAXK];
const int M = 10;
void rec(int d, int p, int* dif) {
  if (p == k) {
    ans = d;
    return;
  }
  if (d >= ans)
    return;
  int rot = dif[p];
  if (rot == 0) {
    rec(d, p + 1, dif);
    return;
  }
  int new_dif[MAXK];
  memcpy(new_dif, dif, sizeof(new_dif));
  rec(d + 1, p + 1, new_dif);
  for (int i = p; i < k; i++) {
    new_dif[i] = (new_dif[i] - rot) % M;
    if (new_dif[i] < 0)
      new_dif[i] += M;
    rec(d + 1, p + 1, new_dif);
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