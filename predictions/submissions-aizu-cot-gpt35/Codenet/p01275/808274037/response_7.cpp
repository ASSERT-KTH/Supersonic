#include <iostream>
using namespace std;

const int M = 10;

int rec(int d, int p, int k, int* dif, int ans) {
  if (p == k) {
    return d;
  }
  if (d >= ans) {
    return ans;
  }

  int rot = dif[p];
  if (rot == 0) {
    return rec(d, p + 1, k, dif, ans);
  }

  int min_d = ans;
  for (int i = p; i < k; i++) {
    dif[i] = (dif[i] - rot) % M;
    min_d = min(min_d, rec(d + 1, p + 1, k, dif, ans));
    dif[i] = (dif[i] + rot + M) % M;
  }

  return min_d;
}

int main() {
  int k;
  while (cin >> k, k) {
    string s, t;
    cin >> s >> t;
    int dif[k];
    for (int i = 0; i < k; i++) {
      dif[i] = ((int)(t[i] - s[i]) + M) % M;
    }
    int ans = k;
    cout << rec(0, 0, k, dif, ans) << endl;
  }
}