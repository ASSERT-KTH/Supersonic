#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using flt = double;
const int MAXN = 100000 + 10;
const flt eps = 1e-7;
int vw[MAXN], pf[MAXN], vf[MAXN], th[MAXN];
int N, pw;
flt calc(flt W) {
  flt cost = W * pw;
  for (int i = 0; i < N; ++i) {
    if (th[i] > W * vw[i]) {
      flt need = th[i] - W * vw[i];
      flt f = need / vf[i];
      cost += f * pf[i];
    }
  }
  return cost;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (cin >> N && N) {
    cin >> pw;
    for (int i = 0; i < N; ++i) {
      cin >> vw[i] >> pf[i] >> vf[i] >> th[i];
    }
    flt left = 0, right = INT_MAX;
    for (int i = 0; i < 200; ++i) {
      flt m1 = (left + left + right) / 3.0;
      flt m2 = (left + right + right) / 3.0;
      flt c1 = calc(m1), c2 = calc(m2);
      if (c1 < c2)
        right = m2;
      else
        left = m1;
    }
    cout << fixed << setprecision(10) << calc(left) << "\n";
  }
  return 0;
}