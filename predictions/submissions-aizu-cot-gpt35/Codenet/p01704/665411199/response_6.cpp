#include <cstdio>

#define MAX 100001

int n, pw;
int vw[MAX], pf[MAX], vf[MAX], th[MAX];

int f(int W) {
  int cost = W * pw;
  for (int i = 0; i < n; i++) {
    if (W * vw[i] > th[i])
      continue;
    int sum1 = (th[i] - W * vw[i]) * 1000;
    int sum2 = sum1 / vf[i];
    cost += sum2 * pf[i];
  }
  return cost;
}

int main() {
  while (1) {
    scanf("%d%d", &n, &pw);
    if (n == 0)
      break;
    for (int i = 0; i < n; i++)
      scanf("%d%d%d%d", &vw[i], &pf[i], &vf[i], &th[i]);

    int l = 0, r = 1000000000;
    while (l < r) {
      int m = (l + r) / 2;
      int res1 = f(m);
      int res2 = f(m + 1);
      if (res1 < res2)
        r = m;
      else
        l = m + 1;
    }
    printf("%.4f\n", f(l) / 1000.0);
  }
  return 0;
}