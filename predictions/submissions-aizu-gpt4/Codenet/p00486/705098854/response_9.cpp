#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll LXY[2][100000];
ll XY[2][100000];
ll oxy[2][2];
int main() {
  ll sum = 0LL, osum = 0LL;
  ll w, h, L, HL, temp, ox, oy, max = 0, dx, dy;
  scanf("%lld %lld", &w, &h);
  scanf("%lld", &L);
  for (ll f1 = 0; f1 < L; f1++) {
    scanf("%lld %lld", &LXY[0][f1], &LXY[1][f1]);
    XY[0][f1] = LXY[0][f1];
    XY[1][f1] = LXY[1][f1];
  }
  nth_element(XY[0], XY[0] + L / 2, XY[0] + L);
  nth_element(XY[1], XY[1] + L / 2, XY[1] + L);
  HL = L / 2;
  if (L == 1) {
    printf("0\n");
    printf("%lld %lld\n", LXY[0][0], LXY[1][0]);
  } else {
    for (ll f1 = 0; f1 < 2; f1++) {
      oxy[0][f1] = XY[f1][HL];
      oxy[1][f1] = XY[f1][HL + 1];
    }
    dx = (oxy[0][0] == oxy[1][0]) ? 1 : 2;
    dy = (oxy[0][1] == oxy[1][1]) ? 1 : 2;
    for (ll f2 = 0; f2 < dx; f2++) {
      for (ll f3 = 0; f3 < dy; f3++) {
        sum = 0LL;
        max = 0LL;
        for (ll f1 = 0; f1 < L; f1++) {
          temp = abs(LXY[0][f1] - oxy[f2][0]) + abs(LXY[1][f1] - oxy[f3][1]);
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