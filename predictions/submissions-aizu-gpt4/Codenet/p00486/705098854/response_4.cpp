#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  long long sum = 0LL, osum = 0LL;
  long long f1, f2, f3, w, h, L, HL, temp, oxy[2][2], *LXY[2], ox, oy, dx, dy;
  vector<long long> XY[2];
  scanf("%lld %lld", &w, &h);
  scanf("%lld", &L);
  LXY[0] = new long long[L];
  LXY[1] = new long long[L];
  for (f1 = 0; f1 < L; f1++) {
    scanf("%lld %lld", &LXY[0][f1], &LXY[1][f1]);
    XY[0].push_back(LXY[0][f1]);
    XY[1].push_back(LXY[1][f1]);
  }
  sort(XY[0].begin(), XY[0].end());
  sort(XY[1].begin(), XY[1].end());
  HL = (L + 1) / 2;
  if (L == 1) {
    printf("0\n");
    printf("%lld %lld\n", LXY[0][0], LXY[1][0]);
  } else {
    oxy[0][0] = XY[0][HL - 1];
    oxy[1][0] = XY[0][HL];
    oxy[0][1] = XY[1][HL - 1];
    oxy[1][1] = XY[1][HL];
    dx = (oxy[0][0] == oxy[1][0]) ? 1 : 2;
    dy = (oxy[0][1] == oxy[1][1]) ? 1 : 2;
    for (f2 = 0; f2 < dx; f2++) {
      for (f3 = 0; f3 < dy; f3++) {
        long long max = 0LL;
        sum = 0LL;
        for (f1 = 0; f1 < L; f1++) {
          temp = abs(LXY[0][f1] - oxy[f2][0]) + abs(LXY[1][f1] - oxy[f3][1]);
          sum += temp;
          max = (max < temp) ? temp : max;
        }
        sum = (sum << 1) - max;
        if (osum == 0 || osum > sum) {
          osum = sum;
          ox = oxy[f2][0];
          oy = oxy[f3][1];
        }
      }
    }
    printf("%lld\n", osum);
    printf("%lld %lld\n", ox, oy);
  }
  delete[] LXY[0];
  delete[] LXY[1];
  return 0;
}