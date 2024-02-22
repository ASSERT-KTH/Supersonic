#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#define N 3
using namespace std;
typedef unsigned long long ull;
bool im[1010][1010], pa[110][110];
int w, h, p, ans;
unordered_set<ull> used;
ull roll[1001][1001] = {};
ull power[110];
bool reverse_flag = false;

void ppp() {
  ull a = 0;
  for (int i = 0; i < p; i++)
    for (int j = 0; j < p; j++)
      a = a * N + pa[i][j];

  if (used.find(a) != used.end())
    return;

  used.insert(a);
  for (int j = 0; j < h; j++) {
    ull b = 0;
    for (int i = 0; i < p; i++)
      b = b * N + im[j][i];
    roll[j][p - 1] = b;
    for (int i = p; i < w; i++) {
      b = b * N + im[j][i] - im[j][i - p] * power[p];
      roll[j][i] = b;
    }
  }
  for (int j = p - 1; j < w; j++) {
    ull b = 0;
    for (int i = 0; i < p; i++)
      b = b * power[p] + roll[i][j];
    if (b == a)
      ans++;
    for (int i = p; i < h; i++) {
      b = b * power[p] + roll[i][j] - roll[i - p][j] * power[p];
      if (b == a)
        ans++;
    }
  }
}

void ch() {
  bool npa[110][110];
  for (int i = 0; i < p; i++)
    for (int j = 0; j < p; j++)
      npa[i][j] = pa[j][p - i - 1];
  for (int i = 0; i < p; i++)
    for (int j = 0; j < p; j++)
      pa[i][j] = npa[i][j];
}

void ch1() {
  reverse_flag = !reverse_flag;
}

int main() {
  power[0] = 1;
  for (int i = 1; i < 110; i++) {
    power[i] = power[i - 1] * N;
  }

  // Rest of the main function remains the same
  // ...
}