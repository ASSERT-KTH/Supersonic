#include <bits/stdc++.h>
#define MAX 100001
#define inf 1e9
using namespace std;

int n, pw;
float vw[MAX], pf[MAX], vf[MAX], th[MAX], inv_vf[MAX];

float f(float W) {
  float cost = W * pw;
  for (int i = 0; i < n; i++) {
    if (W * vw[i] > th[i])
      continue;
    float sum1 = th[i] - W * vw[i];
    float sum2 = sum1 * inv_vf[i]; // Replaced division by multiplication
    cost += sum2 * pf[i];
  }
  return cost;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while (1) {
    cin >> n >> pw;
    if (n == 0)
      break;
    for (int i = 0; i < n; i++){
      cin >> vw[i] >> pf[i] >> vf[i] >> th[i];
      inv_vf[i] = 1.0f / vf[i]; // Inverting vf[i]
    }
    float l = 0, r = inf, m1, m2, res1, res2;
    for (int i = 0; i < 200; i++) {
      m1 = (l * 2.0f + r) / 3.0f;
      m2 = (l + r * 2.0f) / 3.0f;
      res1 = f(m1);
      res2 = f(m2);
      if (res1 < res2)
        r = m2;
      else
        l = m1;
    }
    printf("%.4f\n", f(l));
  }
  return 0;
}