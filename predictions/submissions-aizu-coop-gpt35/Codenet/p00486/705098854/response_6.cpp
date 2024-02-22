#include <cstdio>
#include <cstdlib>
#include <vector>

int main() {
  long long sum = 0LL, osum = 0LL;
  long long w, h, L, HL, temp, *LXY[2], ox, oy, max = 0, dx, dy;
  std::vector<long long> XY[2];
  
  std::scanf("%lld %lld", &w, &h);
  std::scanf("%lld", &L);

  LXY[0] = new long long[L];
  LXY[1] = new long long[L];
  
  for (int f1 = 0; f1 < L; f1++) {
    std::scanf("%lld %lld", &LXY[0][f1], &LXY[1][f1]);
    XY[0].push_back(LXY[0][f1]);
    XY[1].push_back(LXY[1][f1]);
  }

  HL = (L + 1) / 2;
  
  if (L == 1) {
    std::printf("0\n");
    std::printf("%lld %lld\n", LXY[0][0], LXY[1][0]);
  } else {
    long long xy_min[2] = {XY[0][HL - 1], XY[1][HL - 1]};
    long long xy_max[2] = {XY[0][HL], XY[1][HL]};
    
    dx = (xy_min[0] == xy_max[0]) ? 1 : 2;
    dy = (xy_min[1] == xy_max[1]) ? 1 : 2;
    
    long long* abs_diff = new long long[L];
    for (int f1 = 0; f1 < L; f1++) {
      abs_diff[f1] = abs(LXY[0][f1] - xy_min[0]) + abs(LXY[1][f1] - xy_min[1]);
    }
    
    for (int f2 = 0; f2 < dx; f2++) {
      for (int f3 = 0; f3 < dy; f3++) {
        sum = 0LL;
        max = 0LL;
        for (int f1 = 0; f1 < L; f1++) {
          temp = abs_diff[f1] + abs(LXY[1][f1] - xy_max[1 - f3]);
          sum += temp;
          if (max < temp)
            max = temp;
        }
        sum *= 2;
        sum -= max;
        if (osum == 0 || osum > sum) {
          osum = sum;
          ox = xy_min[f2];
          oy = xy_max[1 - f3];
        }
      }
    }
    
    delete[] abs_diff;
    
    osum *= 4;
    
    std::printf("%lld\n", osum);
    std::printf("%lld %lld\n", ox, oy);
  }

  delete[] LXY[0];
  delete[] LXY[1];

  return 0;
}