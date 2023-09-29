#include <bits/stdc++.h>
#define N 3
using namespace std;
typedef unsigned long long ull;
bool im[1010][1010], pa[1010][110];
int w, h, p, ans;
vector<ull> used;
void ppp() {
  ull a = 0;
  ull roll[1001][1001] = {};
  for (int i = 0; i < p; i++)
    for (int j = 0; j < p; j++)
      a = a * N + pa[i][j];
  for (int i = 0; i < used.size(); i++)
    if (used[i] == a)
      return;
  used.push_back(a);
  for (int j = 0; j < h; j++) {
    ull b = 0, g = 1;
    for (int i = 0; i < p; i++)
      b = b * N + im[j][i], g *= N;
    roll[j][p - 1] = b;
    for (int i = p; i < w; i++) {
      b = b * N + im[j][i] - im[j][i - p] * g;
      roll[j][i] = b;
    }
  }
  for (int j = p - 1; j < w; j++) {
    ull b = 0, g = 1, n = 1;
    for (int i = 0; i < p; i++)
      n *= N;
    for (int i = 0; i < p; i++)
      b = b * n + roll[i][j], g *= n;
    if (b == a)
      ans++;
    for (int i = p; i < h; i++) {
      b = b * n + roll[i][j] - roll[i - p