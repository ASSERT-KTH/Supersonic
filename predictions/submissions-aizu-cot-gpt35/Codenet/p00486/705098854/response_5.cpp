#include <cstdio>
#include <vector>
using namespace std;

int main() {
  long long sum = 0LL, osum = 0LL;
  long long L, HL, oxy[2][2], *LXY[2], ox, oy, dx, dy;
  vector<long long> XY[2];

  scanf("%lld", &L);
  for (int f1 = 0; f1 < 2; f1++)
    LXY[f1] = new long long[L];

  for (int f1 = 0; f1 < L; f1++) {
    scanf("%lld %lld", &LXY[0][f1], &LXY[1][f1]);
    XY[0].push_back(LXY[0][f1]);
    XY[1].push_back(LXY[1][f1]);
  }

  HL = (L + 1) / 2;

  if (L == 1) {
    printf("0\n");
    printf("%lld %lld\n", LXY[0][0], LXY[1][0]);
  } else {
    nth_element(XY[0].begin(), XY[0].begin() + HL - 1, XY[0].end());
    nth_element(XY[1].begin(), XY[1].begin() + HL - 1, XY[1].end());

    for (int f1 = 0; f1 < 2; f1++) {
      oxy[0][f1] = XY[f1][HL - 1];
      oxy[1][f1] = XY[f1][HL];
    }

    dx = (oxy[0][0] == oxy[1][0]) ? 1 : 2;
    dy = (oxy[0][1] == oxy[1][1]) ? 1 : 2;

    for (int f2 = 0; f2 < dx; f2++) {
      for (int f3 = 0; f3 < dy; f3++) {
        sum = 0LL;
        long long max = 0LL;

        for (int f1 = 0; f1 < L; f1++) {
          long long temp = (long long)abs(LXY[0][f1] - oxy[f2][0]) +
                           abs(LXY[1][f1] - oxy[f3][1]);
          sum += temp;
          if (max < temp)
            max = temp;
        }

        sum *= 2;
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
  }

  return 0;
}