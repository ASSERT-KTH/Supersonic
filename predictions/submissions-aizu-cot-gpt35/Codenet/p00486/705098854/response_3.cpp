#include <cstdio>
#include <cmath>
#include <array>

int main() {
  long long sum = 0LL, osum = 0LL;
  long long f1, f2, f3, w, h, L, HL, temp, ox, oy, max = 0, dx, dy;
  std::array<std::array<long long, 2>, 2> oxy;
  std::array<std::array<long long, 2>, 2> LXY;
  std::array<long long, 2> XY[2];

  scanf("%lld %lld", &w, &h);
  scanf("%lld", &L);

  HL = (L + 1) / 2;

  for (f1 = 0; f1 < L; f1++) {
    scanf("%lld %lld", &LXY[0][f1], &LXY[1][f1]);
    XY[0][f1] = LXY[0][f1];
    XY[1][f1] = LXY[1][f1];
  }

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
        sum = 0LL;
        max = 0LL;

        for (f1 = 0; f1 < L; f1++) {
          temp = std::abs(LXY[0][f1] - oxy[f2][0]) + std::abs(LXY[1][f1] - oxy[f3][1]);
          sum += temp;
          if (max < temp)
            max = temp;
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
  }

  return 0;
}