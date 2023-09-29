#include <iostream>
#include <algorithm>
#define MAX 100001
#define inf 1e9
using namespace std;
int n, pw;
double vw[MAX], pf[MAX], vf[MAX], th[MAX];
double f(double W) {
  double cost = W * pw;
  for (int i = 0; i < n; i++) {
    double Wvw = W * vw[i];
    if (Wvw > th[i])
      continue;
    double sum = (th[i] - Wvw) / vf[i];
    cost += sum * pf[i];
  }
  return cost;
}
int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  while (cin >> n >> pw && n != 0) {
    for (int i = 0; i < n; i++)
      cin >> vw[i] >> pf[i] >> vf[i] >> th[i];
    double l = 0, r = inf;
    for (int i = 0; i < 200; i++) {
      double m1 = l + (r-l)/3 ;
      double m2 = r - (r-l)/3 ;
      if (f(m1) < f(m2))
        r = m2;
      else
        l = m1;
    }
    printf("%.4f\n", f(l));
  }
  return 0;
}