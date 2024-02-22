#include <bits/stdc++.h>
#define N 3
using namespace std;
typedef unsigned long long ull;
bool im[1010][1010], pa[110][110];
int w, h, p, ans;
unordered_set<ull> used; // Use unordered_set instead of vector
void ppp() {
  ull a = 0;
  ull roll[1001][1001] = {};
  for (int i = 0; i < p; i++)
    for (int j = 0; j < p; j++)
      a = a * N + pa[i][j];
  if (used.count(a)) // Check existence in O(1)
      return;
  used.insert(a); // Insert in O(1)
  ull g = pow(N, p); // Compute g once
  for (int j = 0; j < h; j++) {
    ull b = 0;
    for (int i = 0; i < p; i++)
      b = b * N + im[j][i];
    roll[j][p - 1] = b;
    for (int i = p; i < w; i++) {
      b = b * N + im[j][i] - im[j][i - p] * g;
      roll[j][i] = b;
    }
  }
  ull n = pow(N, p); // Compute n once
  for (int j = p - 1; j < w; j++) {
    ull b = 0, g = 1;
    for (int i = 0; i < p; i++)
      b = b * n + roll[i][j], g *= n;
    if (b == a)
      ans++;
    for (int i = p; i < h; i++) {
      b = b * n + roll[i][j] - roll[i - p][j] * g;
      if (b == a)
        ans++;
    }
  }
}
// Rest of the code remains the same...