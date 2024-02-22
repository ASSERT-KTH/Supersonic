#include <cstdio>
#include <climits>
#include <iostream>
using namespace std;

const int MAXN = 100000 + 10;
const double eps = 1e-7;

double calc(double W, int* vw, int* pf, int* vf, int* th, int N, int pw) {
  double cost = W * pw;
  for (int i = 0; i < N; ++i) {
    double need = th[i] - W * vw[i];
    if (need <= 0) {
      continue;
    }
    double f = need / vf[i];
    cost += f * pf[i];
  }
  return cost;
}

int main() {
  int N;
  while (cin >> N && N) {
    int pw;
    cin >> pw;
    int vw[MAXN], pf[MAXN], vf[MAXN], th[MAXN];
    for (int i = 0; i < N; ++i) {
      cin >> vw[i] >> pf[i] >> vf[i] >> th[i];
    }
    double left = 0, right = INT_MAX;
    for (int _ = 0; _ < 200; ++_) {
      double m1 = (left + left + right) / 3.0;
      double m2 = (left + right + right) / 3.0;
      double c1 = calc(m1, vw, pf, vf, th, N, pw);
      double c2 = calc(m2, vw, pf, vf, th, N, pw);
      if (c1 < c2) {
        right = m2;
      } else {
        left = m1;
      }
    }
    printf("%.10f\n", calc(left, vw, pf, vf, th, N, pw));
  }
  return 0;
}