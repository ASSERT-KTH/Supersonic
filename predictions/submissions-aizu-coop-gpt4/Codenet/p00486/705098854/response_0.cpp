#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

long long LXY[2][100000], XY[2][100000];

int main() {
  long long sum = 0LL, osum = 0LL;
  long long w, h, L, HL, temp, oxy[2][2], ox, oy, max = 0, dx, dy;

  scanf("%lld %lld", &w, &h);
  scanf("%lld", &L);
  for (int f1 = 0; f1 < L; f1++) {
    scanf("%lld %lld", &LXY[0][f1], &LXY[1][f1]);
    XY[0][f1] = LXY[0][f1];
    XY[1][f1] = LXY[1][f1];
  }
  sort(XY[0], XY[0] + L);
  sort(XY[1], XY[1] + L);

  HL = (L + 1) / 2;
  if (L == 1) {
    printf("0\n");
    printf("%lld %lld\n", LXY[0][0], LXY[1][0]);
  } else {
    for (int f1 = 0; f1 < 2; f1++) {
      oxy[0][f1] = XY[f1][HL - 1];
      oxy[1][f1] = XY[f1][HL];
    }
    dx = (oxy[0][0] == oxy[1][0]) ? 1 : 2;
    dy = (oxy[0][1] == oxy[1][1]) ? 1 : 2;
    for (int f2 = 0; f2 < dx; f2++) {
      for (int f3 = 0; f3 < dy; f3++) {
        sum = 0LL;
        max = 0LL;
        for (int f1 = 0; f1 < L; f1++) {
          temp = abs(LXY[0][f1] - oxy[f2][0]) + abs(LXY[1][f1] - oxy[f3][1]);
          sum += temp;
          if(max < temp) max = temp;
        }
        sum = sum*2 - max;
        if(osum == 0 || osum > sum) {
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