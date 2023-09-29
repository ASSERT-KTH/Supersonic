#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int M = 10;
vector<int> dif(12);
int k, ans;

void rec(int d, int p) {
  if (p == k) {
    ans = min(d, ans);
    return;
  }

  int rot = dif[p];
  if (rot == 0) {
    rec(d, p + 1);
    return;
  }

  rec(d + 1, p + 1);

  for (int i = p; i < k; i++) {
    dif[i] = (dif[i] - rot + M) % M;
    rec(d + 1, p + 1);
    dif[i] = (dif[i] + rot) % M;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (cin >> k, k) {
    string s, t;
    cin >> s >> t;

    for (int i = 0; i < k; i++)
      dif[i] = (t[i] - s[i] + M) % M;

    ans = k;
    rec(0, 0);
    cout << ans << "\n";
  }

  return 0;
}