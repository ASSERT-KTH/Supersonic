#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
long long LXY[2][10000];

int main() {
  long long sum, osum = 0LL;
  long long f1, f2, f3, w, h, L, HL, temp, oxy[2][2], ox, oy, max, dx, dy;
  vector<long long> XY[2];
  scanf("%lld %lld", &w, &h);
  scanf("%lld", &L);
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
    dx = (oxy[0][0] == oxy[1][0]) ? 1 : 2;
    dy = (oxy[0][1] == oxy[1][1]) ? 1 : 2;
    for (f2 = 0; f2 < dx; f2++) {
      for (f3 = 0; f3 < dy; f3++) {
        long long ox_temp = oxy[f2][0];
        long long oy_temp = oxy[f3][1];
        for (f1 = 0; f1 < L; f1++) {
          temp = abs(LXY[0][f1] - ox_temp) + abs(LXY[1][f1] - oy_temp);
          sum += temp;
          if (max < temp)
            max = temp;
        }
        sum *= 2;
        sum -= max;
        if (osum == 0 || osum > sum) {
          osum = sum;
          ox = ox_temp;
          oy = oy_temp;
        }
      }
    }
    printf("%lld\n", osum);
    printf("%lld %lld\n", ox, oy);
  }
  return 0;
}