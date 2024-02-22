#include <cstdio>
#include <climits>

const int MAXN = 100000 + 10;

int* vw;
int* pf;
int* vf;
int* th;

double calc(double W, int N) {
  double cost = W * pw;
  for (int i = 0; i < N; ++i) {
    int need = th[i] - W * vw[i];
    if (need <= 0)
      continue;
    int f = need / vf[i];
    cost += f * pf[i];
  }
  return cost;
}

int main() {
  int N, pw;
  while (scanf("%d", &N) == 1 && N) {
    scanf("%d", &pw);

    vw = new int[N];
    pf = new int[N];
    vf = new int[N];
    th = new int[N];

    for (int i = 0; i < N; ++i) {
      scanf("%d%d%d%d", &vw[i], &pf[i], &vf[i], &th[i]);
    }

    double left = 0, right = INT_MAX;
    double step = (right - left) / 300.0;

    for (int _ = 0; _ < 200; ++_) {
      double m1 = left + step;
      double m2 = right - step;
      double c1 = calc(m1, N);
      double c2 = calc(m2, N);
      if (c1 < c2)
        right = m2;
      else
        left = m1;
      step = (right - left) / 300.0;
    }

    printf("%.10f\n", calc(left, N));

    delete[] vw;
    delete[] pf;
    delete[] vf;
    delete[] th;
  }

  return 0;
}