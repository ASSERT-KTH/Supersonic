#include <iostream>
#include <algorithm>
using namespace std;
const int M = 10;
int dif[12];

int rec(int d, int p, int k, int ans) {
  if (p == k) {
    return d;
  }
  if (d >= ans)
    return ans;
  int rot = dif[p];
  if (rot == 0) {
    return rec(d, p + 1, k, ans);
  }
  ans = min(ans, rec(d + 1, p + 1, k, ans));
  for (int i = p; i < k; i++) {
    dif[i] = (dif[i] - rot + M) % M;
    ans = min(ans, rec(d + 1, p + 1, k, ans));
  }
  for (int i = p; i < k; i++)
    dif[i] = (dif[i] + rot) % M;
  return ans;
}

int main() {
  int k;
  while (cin >> k, k) {
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < k; i++) {
      dif[i] = ((int)(t[i] - s[i]) + M) % M;
    }
    cout << rec(0, 0, k, k) << endl;
  }
}