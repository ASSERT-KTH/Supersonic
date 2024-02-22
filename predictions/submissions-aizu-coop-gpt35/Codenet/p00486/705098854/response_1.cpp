#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long sum = 0LL, osum = 0LL;
  long long f1, f2, f3, w, h, L, HL, temp, oxy[2][2], ox, oy, max = 0, dx, dy;
  vector<long long> XY[2];
  scanf("%lld %lld", &w, &h);
  scanf("%lld", &L);
  vector<long long> LXY[2];

  for (f1 = 0; f1 < L; f1++) {
    scanf("%lld %lld", &LXY[0][f1], &LXY[1][f1]);
    XY[0].push_back(LXY[0][f1]);
    XY[1].push_back(LXY[1][f1]);
  }

  HL = (L + 1) / 2;

  // Use nth_element to find the median elements
  nth_element(XY[0].begin(), XY[0].begin() + HL, XY[0].end());
  nth_element(XY[1].begin(), XY[1].begin() + HL, XY[1].end());

  if (L == 1) {
    printf("0\n");
    printf("%lld %lld\n", LXY[0][0], LXY[1][0]);
  } else {
    for (f2 = 0; f2 < 2; f2++) {
      for (f3 = 0; f3 < 2; f3++) {
        sum = 0LL;
        max = 0LL;
        for (f1 = 0; f1 < L; f1++) {
          temp = (long long)abs(LXY[0][f1] - XY[0][f2 * HL]) +
                 abs(LXY[1][f1] - XY[1][f3 * HL]);
          sum += temp;
          if (max < temp)
            max = temp;
        }
        sum *= 2;
        sum -= max;
        if (osum == 0 || osum > sum) {
          osum = sum;
          ox = XY[0][f2 * HL];
          oy = XY[1][f3 * HL];
        }
      }
    }
    printf("%lld\n", osum);
    printf("%lld %lld\n", ox, oy);
  }
  return 0;
}