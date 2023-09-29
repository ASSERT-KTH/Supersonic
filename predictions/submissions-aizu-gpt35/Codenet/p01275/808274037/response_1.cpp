#include <iostream>
using namespace std;
int k, ans;
int dif[12];
const int M = 10;
void rec(int d, int p, int tot) {
  if (p == k) {
    ans = min(ans, tot);
    return;
  }
  if (tot >= ans)
    return;
  int rot = dif[p];
  if (rot == 0) {
    rec(d, p + 1, tot);
    return;
  }
  if (tot + k - p < ans) {
    int tdif[12];
    for (int i = p; i < k; i++)
      tdif[i] = dif[i];
    for (int i = p; i < k; i++) {
      dif[i] = (dif[i] - rot + M) % M;
    }
    rec(d + 1, p + 1, tot + 1);
    for (int i = p; i < k; i++)
      dif[i] = (dif[i] + rot) % M;
    rec(d, p + 1, tot);
    for (int i = p; i < k; i++)
      dif[i] = tdif[i];
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
    rec(0, 0, 0);
    cout << ans << endl;
  }
}