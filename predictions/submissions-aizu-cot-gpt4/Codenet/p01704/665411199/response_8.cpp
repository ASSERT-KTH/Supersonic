#include <iostream>
#include <cstdio>
#include <cmath>
#define MAX 100001
#define inf 1e9
using namespace std;
int n, pw;
float vw[MAX], pf[MAX], vf[MAX], th[MAX];
float f(float W) {
  float cost = W * pw;
  for (int i = 0; i < n; i++) {
    float W_vw = W * vw[i];
    if (W_vw > th[i])
      continue;
    float sum1 = th[i] - W_vw;
    float sum2 = sum1 / vf[i];
    cost += sum2 * pf[i];
  }
  return cost;
}
int main() {
  while (1) {
    cin >> n >> pw;
    if (n == 0)
      break;
    for (int i = 0; i < n; i++)
      cin >> vw[i] >> pf[i] >> vf[i] >> th[i];
    float l = 0, r = inf;
    for (int i = 0; i < 200; i++) {
      float lr = l * 2.0 + r;
      float rl = l + r * 2.0;
      float m1 = lr / 3.0;
      float m2 = rl / 3.0;
      float res1 = f(m1);
      float res2 = f(m2);
      if (res1 < res2)
        r = m2;
      else
        l = m1;
    }
    printf("%.4f\n", f(l));
  }
  return 0;
}