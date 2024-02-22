#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000 + 10;
const float eps = 1e-7;

int vw[MAXN], pf[MAXN], vf[MAXN], th[MAXN];
int N, pw;

float calc(float W, float* need) {
  float cost = W * pw;
  for (int i = 0; i < N; ++i) {
    float f = need[i] / vf[i];
    cost += f * pf[i];
  }
  return cost;
}

int main() {
  while (scanf("%d", &N) == 1 && N) {
    scanf("%d", &pw);
    for (int i = 0; i < N; ++i) {
      scanf("%d%d%d%d", vw + i, pf + i, vf + i, th + i);
    }
    float left = 0, right = INT_MAX;
    float need[MAXN];
    for (int i = 0; i < N; ++i) {
      need[i] = th[i] - left * vw[i];
    }
    const int numIterations = 200;
    for (int _ = 0; _ < numIterations; ++_) {
      float m1 = (left + left + right) / 3.0;
      float m2 = (left + right + right) / 3.0;
      float c1 = calc(m1, need);
      float c2 = calc(m2, need);
      if (c1 < c2)
        right = m2;
      else
        left = m1;
    }
    printf("%.10f\n", calc(left, need));
  }
  return 0;
}