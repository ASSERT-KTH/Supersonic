#include <bits/stdc++.h>
#define N 3
using namespace std;
typedef unsigned long long ull;
bool im[1010][1010], pa[110][110];
ull roll[1001][1001] = {};
int w, h, p, ans;
unordered_set<ull> used; // change from vector to unordered_set
ull n_pow[1010]; // precomputed powers of N
void ppp() {
  ull a = 0;
  for (int i = 0; i < p; i++)
    for (int j = 0; j < p; j++)
      a = a * N + pa[i][j];
  if (used.count(a)) // faster check for duplicates
    return;
  used.insert(a); // faster insertion
  for (int j = 0; j < h; j++) {
    ull b = 0, g = n_pow[p]; // use precomputed value
    for (int i = 0; i < p; i++)
      b = b * N + im[j][i];
    roll[j][p - 1] = b;
    for (int i = p; i < w; i++) {
      b = b * N + im[j][i] - im[j][i - p] * g;
      roll[j][i] = b;
    }
  }
  for (int j = p - 1; j < w; j++) {
    ull b = 0, g = n_pow[p]; // use precomputed value
    for (int i = 0; i < p; i++)
      b = b * n_pow[p] + roll[i][j]; // use precomputed value
    if (b == a)
      ans++;
    for (int i = p; i < h; i++) {
      b = b * n_pow[p] + roll[i][j] - roll[i - p][j] * g; // use precomputed value
      if (b == a)
        ans++;
    }
  }
}
// rest of the code remains the same

int main() {
  // precompute powers of N
  n_pow[0] = 1;
  for (int i = 1; i <= 1000; i++)
    n_pow[i] = n_pow[i - 1] * N;
  // rest of the code remains the same
  return 0;
}