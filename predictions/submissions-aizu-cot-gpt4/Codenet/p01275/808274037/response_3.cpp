#include <iostream>
using namespace std;
int k, ans;
const int M = 10;
void rec(int *dif, int d, int p) {
  if (p == k) {
    ans = d;
    return;
  }
  if (d >= ans)
    return;
  int rot = dif[p];
  if (rot == 0) {
    rec(dif, d, p + 1);
    return;
  }
  for (int i = p; i < k; i++) {
    dif[i] = (dif[i] - rot + M) % M;
  }
  rec(dif, d + 1, p + 1);
  for (int i = p; i < k; i++)
    dif[i] = (dif[i] + rot + M) % M;
}
int main() {
  while (cin >> k, k) {
    string s, t;
    cin >> s >> t;
    int *dif = new int[k];
    int temp;
    for (int i = 0; i < k; i++) {
      temp = ((int)(t[i] - s[i]) + M);
      dif[i] = temp % M;
    }
    ans = k;
    rec(dif, 0, 0);
    cout << ans << endl;
    delete [] dif;
  }
}