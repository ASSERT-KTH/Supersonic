#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <climits>
using namespace std;

int main() {
  long long L, w, h, HL, temp, sum, max, osum=LLONG_MAX, f1, f2, f3, ox, oy, dx, dy;
  long long LXY[2][5000], oxy[2][2];

  scanf("%lld %lld", &w, &h);
  scanf("%lld", &L);
  
  for (f1 = 0; f1 < L; f1++)
    scanf("%lld %lld", &LXY[0][f1], &LXY[1][f1]);
  
  stable_sort(LXY[0], LXY[0] + L);
  stable_sort(LXY[1], LXY[1] + L);
  
  HL = (L + 1) / 2;
  if (L == 1) {
    printf("0\n");
    printf("%lld %lld\n", LXY[0][0], LXY[1][0]);
  } else {
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
          temp = (long long)abs(LXY[0][f1] - oxy[f2][0]) +
                 (long long)abs(LXY[1][f1] - oxy[f3][1]);
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