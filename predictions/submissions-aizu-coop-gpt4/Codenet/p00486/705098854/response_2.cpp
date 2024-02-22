#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long sum = 0LL, osum = 0LL;
  long long f1, f2, f3, w, h, L, HL, temp, oxy[2][2], ox, oy, max = 0, dx, dy;
  vector<long long> LXY[2];

  scanf("%lld %lld", &w, &h);
  scanf("%lld", &L);

  LXY[0].resize(L);
  LXY[1].resize(L);

  for (f1 = 0; f1 < L; f1++) {
    scanf("%lld %lld", &LXY[0][f1], &LXY[1][f1]);
  }

  for (f1 = 0; f1 < 2; f1++) {
    nth_element(LXY[f1].begin(), LXY[f1].begin() + L / 2, LXY[f1].end());
    oxy[0][f1] = LXY[f1][L / 2];
    if (L % 2 == 0) {
      nth_element(LXY[f1].begin(), LXY[f1].begin() + L / 2 - 1, LXY[f1].end());
      oxy[1][f1] = LXY[f1][L / 2 - 1];
    } else {
      oxy[1][f1] = oxy[0][f1];
    }
  }

  if (L == 1) {
    printf("0\n");
    printf("%lld %lld\n", LXY[0][0], LXY[1][0]);
  } else {
    dx = (oxy[0][0] == oxy[1][0]) ? 1 : 2;
    dy = (oxy[0][1] == oxy[1][1]) ? 1 : 2;

    for (f2 = 0; f2 < dx; f2++) {
      for (f3 = 0; f3 < dy; f3++) {
        sum = 0LL;
        max = 0LL;

        for_each(LXY[0].begin(), LXY[0].end(), [&](long long &x) {
          temp = abs(x - oxy[f2][0]) + abs(LXY[1][&x - LXY[0].begin()] - oxy[f3][1]);
          sum += temp;
          if (max < temp)
            max = temp;
        });

        sum *= 2;
        sum -= max;
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

  return 0;
}