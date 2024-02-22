#include <bits/stdc++.h>
#define MAX 100001
#define inf 1e9
using namespace std;
int n, pw;
double vw[MAX], pf[MAX], vf[MAX], th[MAX], rvf[MAX]; // added rvf array to store reciprocal of vf
unordered_map<double, double> memo; // added memo to store previously calculated function values

double f(double W) {
  // check if function value is already calculated
  if (memo.find(W) != memo.end()) {
    return memo[W];
  }

  double cost = W * pw;
  for (int i = 0; i < n; i++) {
    if (W * vw[i] > th[i])
      continue;
    double sum1 = th[i] - W * vw[i];
    double sum2 = sum1 * rvf[i]; // replaced division with multiplication
    cost += sum2 * pf[i];
  }
  
  // store function value in memo
  memo[W] = cost;
  return cost;
}

int main() {
  while (1) {
    cin >> n >> pw;
    if (n == 0)
      break;
    for (int i = 0; i < n; i++){
      cin >> vw[i] >> pf[i] >> vf[i] >> th[i];
      rvf[i] = 1.0 / vf[i]; // calculate and store reciprocal of vf[i]
    }
      
    double l = 0, r = inf;
    for (int i = 0; i < 200; i++) {
      double m1 = (l * 2.0 + r) / 3.0;
      double m2 = (l + r * 2.0) / 3.0;
      double res1 = f(m1);
      double res2 = f(m2);
      if (res1 < res2)
        r = m2;
      else
        l = m1;
    }
    printf("%.4f\n", f(l));
    memo.clear(); // clear memo for the next iteration
  }
  return 0;
}