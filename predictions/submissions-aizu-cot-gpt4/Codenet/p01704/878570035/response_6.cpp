#include <iostream>
#include <climits>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef double flt;
const int MAXN = 100000 + 10;
const flt eps = 1e-7;

flt calc(flt W, int vw[], int pf[], int vf[], int th[], int N, int pw) {
  flt cost = W * pw;
  for (int i = 0; i < N; ++i) {
    flt need = th[i] - W * vw[i];
    if (need > 0) {
      flt f = need / vf[i];
      cost += f * pf[i];
    }
  }
  return cost;
}

int main() {
  ios_base::sync_with_stdio(false);
  int N, pw;
  int vw[MAXN], pf[MAXN], vf[MAXN], th[MAXN];
  while (cin >> N && N) {
    cin >> pw;
    for (int i = 0; i < N; ++i) {
      cin >> vw[i] >> pf[i] >> vf[i] >> th[i];
    }
    flt left = 0, right = INT_MAX;
    for (int _ = 0; _ < 200; ++_) {
      flt m1 = (left + left + right) / 3.0;
      flt m2 = (left + right + right) / 3.0;
      flt c1 = calc(m1, vw, pf, vf, th, N, pw), c2 = calc(m2, vw, pf, vf, th, N, pw);
      if (c1 < c2)
        right = m2;
      else
        left = m1;
    }
    cout << fixed << setprecision(10) << calc(left, vw, pf, vf, th, N, pw) << endl;
  }
  return 0;
}