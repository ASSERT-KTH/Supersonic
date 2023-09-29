#include <iostream>
#include <cmath>
#include <cstdio>
#define MAX 100001
#define inf 1e9
using namespace std;
int n, pw;
double vw[MAX], pf[MAX], vf[MAX], th[MAX];
inline double f(double W) {
  double cost = W * pw;
  double temp;
  for (int i = 0; i < n; i++) {
    temp = th[i] - W * vw[i];
    if (temp > 0)
       cost += (temp / vf[i]) * pf[i];   
  }
  return cost;
}
int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  while (cin >> n >> pw && n) {
    for (int i = 0; i < n; i++)
      cin >> vw[i] >> pf[i] >> vf[i] >> th[i];
    double l = 0, r = inf, m1, m2, res1, res2;
    for (int i = 0; i < 200; i++) {
      m1 = l + (r - l) / 3;
      m2 = r - (r - l) / 3;
      res1 = f(m1);
      res2 = f(m2);
      (res1 < res2) ? r = m2 : l = m1;
    }
    printf("%.4f\n", f(l));
  }
  return 0;
}