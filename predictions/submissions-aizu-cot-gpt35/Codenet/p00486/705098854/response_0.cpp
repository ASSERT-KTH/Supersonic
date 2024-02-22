#include <cstdio>
#include <cstdlib>
#include <iostream>

int main() {
  long long sum = 0LL, osum = 0LL;
  long long f1, f2, f3, w, h, L, HL, oxy[2][2], LXY[2][100000], ox, oy, max = 0,
                                                                 dx, dy;
  scanf("%lld %lld", &w, &h);
  scanf("%lld", &L);
  for (f1 = 0; f1 < L; f1++) {
    scanf("%lld %lld", &LXY[0][f1], &LXY[1][f1]);
  }
  
  std::sort(LXY[0], LXY[0] + L);
  std::sort(LXY[1], LXY[1] + L);
  
  HL = (L + 1) / 2;
  
  for (f1 = 0; f1 < 2; f1++) {
    oxy[0][f1] = LXY[f1][HL - 1];
    oxy[1][f1] = LXY[f1][HL];
  }
  
  dx = (oxy[0][0] == oxy[1][0]) ? 1 : 2;
  dy = (oxy[0][1] == oxy[1][1]) ? 1 : 2;
  
  for (f2 = 0; f2 < dx; f2++) {
    for (f3 = 0; f3 < dy; f3++) {
      sum = 0LL;
      max = 0LL;
      for (f1 = 0; f1 < L; f1++) {
        sum += std::abs(LXY[0][f1] - oxy[f2][0]) +
               std::abs(LXY[1][f1] - oxy[f3][1]);
        if (max < sum)
          max = sum;
      }
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
  
  return 0;
}