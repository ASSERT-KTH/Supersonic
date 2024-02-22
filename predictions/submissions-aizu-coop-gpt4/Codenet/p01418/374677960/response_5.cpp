#include <bits/stdc++.h>
using namespace std;
int K, R, L;
double P, E, T;

double dfs(int d, double l, double r) {
  double mid = (l + r) / 2;
  if (!d) {
    return ((mid > T - E) && (mid < T + E)) ? 1.0 : 0.0;
  }
  if (r < T - E || l > T + E) {
    return 0.0;
  }
  
  double res = dfs(d - 1, mid, r); // store result of dfs() call in a variable
  if (mid >= T) {
    return (1.0 - P) * dfs(d - 1, l, mid) + P * res; 
  }
  return (1.0 - P) * res + P * dfs(d - 1, l, mid);
}

int main() {
  scanf("%d %d %d %lf %lf %lf", &K, &L, &R, &P, &E, &T);
  printf("%.9f\n", dfs(K, L, R));
  return 0;
}