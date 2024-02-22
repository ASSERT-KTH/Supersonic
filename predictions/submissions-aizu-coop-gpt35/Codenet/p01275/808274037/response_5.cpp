#include <iostream>
#include <vector>
using namespace std;

const int M = 10;

void rec(int d, int p, vector<int>& dif, int& ans) {
  if (p == dif.size()) {
    ans = d;
    return;
  }
  if (d >= ans)
    return;
  int rot = dif[p];
  if (rot == 0) {
    rec(d, p + 1, dif, ans);
    return;
  }
  rec(d + 1, p + 1, dif, ans);
  for (int i = p; i < dif.size(); i++) {
    int new_dif = (dif[i] - rot) % M;
    rec(d + 1, i + 1, dif, ans);
    dif[i] = (new_dif + M) % M;
  }
}

int main() {
  int k;
  while (cin >> k, k) {
    string s, t;
    cin >> s >> t;
    vector<int> dif(k);
    for (int i = 0; i < k; i++) {
      dif[i] = ((int)(t[i] - s[i]) + M) % M;
    }
    int ans = k;
    rec(0, 0, dif, ans);
    cout << ans << endl;
  }
}