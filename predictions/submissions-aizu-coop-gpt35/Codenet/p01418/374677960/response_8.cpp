#include <bits/stdc++.h>
using namespace std;

float dfs(int d, float l, float r, float mid, float acc) {
  if (!d)
    return (T - E < mid && mid < T + E) ? 1 : 0;
  if (r < T - E || T + E < l)
    return 0;
  if (mid >= T)
    return (1.0f - P) * dfs(d - 1, l, mid, (l + mid) / 2, acc) + P * acc;
  return (1.0f - P) * dfs(d - 1, mid, r, (mid + r) / 2, acc);
}

int main() {
  int K, R, L;
  float P, E, T;
  cin >> K >> L >> R >> P >> E >> T;
  float mid = (L + R) / 2;
  float result = dfs(K, L, R, mid, 1);
  printf("%.9f\n", result);
  return 0;
}