#include <bits/stdc++.h>
#define N 3
using namespace std;
typedef unsigned long long ull;
bool **im, **pa;
ull roll[1010][1010] = {};
int w, h, p, ans;
unordered_set<ull> used;

void ppp() {
  ull a = 0, powers[1001];
  powers[0] = 1;
  for (int i = 1; i <= 1000; i++) powers[i] = powers[i-1] * N;
  for (int i = 0; i < p; i++)
    for (int j = 0; j < p; j++)
      a = a * N + pa[i][j];
  if (used.find(a) != used.end())
      return;
  used.insert(a);
  for (int j = 0; j < h; j++) {
    ull b = 0, g = 1;
    for (int i = 0; i < p; i++)
      b = b * N + im[j][i], g = powers[i+1];
    roll[j][p - 1] = b;
    for (int i = p; i < w; i++) {
      b = b * N + im[j][i] - im[j][i - p] * g;
      roll[j][i] = b;
    }
  }
  for (int j = p - 1; j < w; j++) {
    ull b = 0, g = 1, n = 1;
    for (int i = 0; i < p; i++)
      n = powers[i+1];
    for (int i = 0; i < p; i++)
      b = b * n + roll[i][j], g = powers[i+1];
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