#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
  long long sum = 0LL, osum = LLONG_MAX;
  long long f1, f2, f3, w, h, L, temp, oxy[2][2], LXY[2][100000], ox, oy, max = 0, dx, dy;
  vector<long long> XY[2];

  scanf("%lld %lld", &w, &h);
  scanf("%lld", &L);

  for (f1 = 0; f1 < L; f1++) {
    scanf("%lld %lld", &LXY[0][f1], &LXY[1][f1]);
    XY[0].push_back(LXY[0][f1]);
    XY[1].push_back(LXY[1][f1]);
  }

  nth_element(XY[0].begin(), XY[0].begin() + L / 2, XY[0].end());
  nth_element(XY[1].begin(), XY[1].begin() + L / 2, XY[1].end());

  oxy[0][0] = XY[0][L / 2 - 1];
  oxy[0][1] = XY[1][L / 2 - 1];
  oxy[1][0] = XY[0][L / 2];
  oxy[1][1] = XY[1][L / 2];

  dx = abs(oxy[0][0] - oxy[1][0]) == 0 ? 1 : 2;
  dy = abs(oxy[0][1] - oxy[1][1]) == 0 ? 1 : 2;

  for (f2 = 0; f2 < dx; f2++) {
    for (f3 = 0; f3 < dy; f3++) {
      sum = 0LL;
      max = 0LL;

      for (f1 = 0; f1 < L; f1++) {
        temp = abs(LXY[0][f1] - oxy[f2][0]) + abs(LXY[1][f1] - oxy[f3][1]);
        sum += temp;
        if (max < temp)
          max = temp;
      }

      sum -= max;

      if (osum > sum) {
        osum = sum;
        ox = oxy[f2][0];
        oy = oxy[f3][1];
      }
    }
  }

  printf("%lld\n", osum);
  printf("%lld %lld\n", ox, oy);

  return 0;
}