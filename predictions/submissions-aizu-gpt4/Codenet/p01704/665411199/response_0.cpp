#include <iostream>
#include <cstdio>
#define MAX 100001
#define INF 1e9

int n, pw;
double vw[MAX], pf[MAX], vf[MAX], th[MAX];

inline double f(double W) {
  double cost = W * pw;
  for (int i = 0; i < n; ++i) {
    double temp = th[i] - W * vw[i];
    if (temp > 0)
      cost += (temp / vf[i]) * pf[i];
  }
  return cost;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  
  while (std::cin >> n >> pw && n) {
    for (int i = 0; i < n; ++i)
      std::cin >> vw[i] >> pf[i] >> vf[i] >> th[i];
      
    double l = 0, r = INF;
    for (int i = 0; i < 200; ++i) {
      double m1 = l + (r - l) / 3;
      double m2 = r - (r - l) / 3;
      if (f(m1) < f(m2))
        r = m2;
      else
        l = m1;
    }
    printf("%.4f\n", f(l));
  }
  return 0;
}