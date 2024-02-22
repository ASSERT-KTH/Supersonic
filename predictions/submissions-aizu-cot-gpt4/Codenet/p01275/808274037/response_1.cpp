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
  int rotated_dif[12]; // To save the state before modifications
  for (int i = p; i < k; i++) {
    rotated_dif[i] = dif[i]; // Save the state
    dif[i] = (dif[i] - rot + M) % M;
  }
  rec(d + 1, p + 1); // Single recursive call
  for (int i = p; i < k; i++) {
    dif[i] = rotated_dif[i]; // Restore the state
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
    rec(0, 0);
    cout << ans << endl;
  }
}