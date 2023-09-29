#include <iostream>
using namespace std;
int k, ans;
int dif[12];
const int M = 10;
void rec(int d, int p, int sum) {
  if (p == k) {
    ans = min(ans, d + sum/M);
    return;
  }
  if (d + sum/M >= ans) // add the sum/M to the condition to check if it is greater than the current answer
    return;
  int rot = dif[p];
  if (rot == 0) {
    rec(d, p + 1, sum);
    return;
  }
  rec(d + 1, p + 1, sum + M - rot); // add the difference of M and rot to the sum
  for (int i = p; i < k; i++) {
    dif[i] = (dif[i] - rot) % M;
    sum -= rot;
    if (sum < 0) sum += M;
    rec(d + 1, p + 1, sum); // pass the updated sum to the recursive call
  }
  for (int i = p; i < k; i++) {
    dif[i] = (dif[i] + rot) % M;
    sum += rot;
    if (sum >= M) sum -= M;
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