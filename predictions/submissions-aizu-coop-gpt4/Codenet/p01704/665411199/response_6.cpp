#include <bits/stdc++.h>
#define MAX 100001
#define inf 1e9
using namespace std;
int n, pw;
float vw[MAX], pf[MAX], vf[MAX], th[MAX];
unordered_map<float, float> memo;

float f(float W) {
  if (memo.count(W)) return memo[W];  // check if result for W has been computed
  float cost = W * pw;
  for (int i = 0; i < n; i++) {
    if (W * vw[i] > th[i])
      continue;
    float sum1 = th[i] - W * vw[i];
    float sum2 = sum1 / vf[i];
    cost += sum2 * pf[i];
  }
  memo[W] = cost;  // store the computed result for W
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
      float m1 = (l * 2.0f + r) / 3.0f;
      float m2 = (l + r * 2.0f) / 3.0f;
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