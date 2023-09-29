#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  long long sum = 0LL, osum = 0LL;
  long long f1, f2, f3, w, h, HL, temp, oxy[2][2], *LXY[2], ox, oy, max = 0,
                                                                       dx, dy;
  vector<long long> XY[2];
  scanf("%lld %lld", &w, &h);
  scanf("%lld", &L);
  for (f1 = 0; f1 < 2; f1++)
    LXY[f1] = new long long[L];
  for (f1 = 0; f1 < L; f1++) {
    scanf("%lld %lld", &LXY[0][f1], &LXY[1][f1]);
    XY[0].push_back(LXY[0][f1]);
    XY[1].push_back(LXY[1][f1]);
  }
  stable_sort(XY[0].begin(), XY[0].end());
  stable_sort(XY[1].begin(), XY[1].end());
  HL = (L + 1) / 2;
  if (L == 1) {
    printf("0\n");
    printf("%lld %lld\n", LXY[0][0], LXY[1][0]);
  } else {
    for (f1 = 0; f1 < 2; f1++) {
      oxy[0][f1] = XY[f1][HL - 1];
      oxy[1][f1] = XY[f1][HL];
    }
  }