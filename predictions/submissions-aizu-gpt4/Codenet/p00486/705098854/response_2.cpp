#include <algorithm>
#include <cstdio>
#include <vector>

int main() {
  long long sum = 0LL, osum = 0LL;
  long long w, h, L, HL, temp, ox, oy, max = 0;
  std::vector<long long> LXY[2], XY[2];
  scanf("%lld %lld", &w, &h);
  scanf("%lld", &L);
  for (auto &i : LXY) i.resize(L);
  for (int f1 = 0; f1 < L; f1++) {
    scanf("%lld %lld", &LXY[0][f1], &LXY[1][f1]);
    XY[0].push_back(LXY[0][f1]);
    XY[1].push_back(LXY[1][f1]);
  }
  std::sort(XY[0].begin(), XY[0].end());
  std::sort(XY[1].begin(), XY[1].end());
  HL = (L + 1) / 2;
  if (L == 1) {
    printf("0\n");
    printf("%lld %lld\n", LXY[0][0], LXY[1][0]);
  } else {
    long long oxy[2][2] = {{XY[0][HL - 1], XY[1][HL - 1]}, {XY[0][HL], XY[1][HL]}};
    int dx = (oxy[0][0] == oxy[1][0]) ? 1 : 2;
    int dy = (oxy[0][1] == oxy[1][1]) ? 1 : 2;
    for (int f2 = 0; f2 < dx; f2++) {
      for (int f3 = 0; f3 < dy; f3++) {
        sum = 0LL;
        max = 0LL;
        for (int f1 = 0; f1 < L; f1++) {
          temp = std::abs(LXY[0][f1] - oxy[f2][0]) + std::abs(LXY[1][f1] - oxy[f3][1]);
          sum += temp;
          if (max < temp)
            max = temp;
        }
        sum = (sum << 1) - max;
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