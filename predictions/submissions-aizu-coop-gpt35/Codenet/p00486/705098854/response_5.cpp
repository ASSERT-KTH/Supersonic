#include <iostream>
#include <vector>

int main() {
  long long sum = 0LL, osum = LLONG_MAX;
  long long f1, f2, f3, L, HL, temp, oxy[2][2], ox, oy, max = 0, dx, dy;
  std::vector<long long> XY[2];

  std::cin >> L;

  for (f1 = 0; f1 < L; f1++) {
    long long x, y;
    std::cin >> x >> y;
    XY[0].push_back(x);
    XY[1].push_back(y);
  }

  HL = (L + 1) / 2;

  std::nth_element(XY[0].begin(), XY[0].begin() + HL - 1, XY[0].end());
  std::nth_element(XY[1].begin(), XY[1].begin() + HL, XY[1].end());

  for (f2 = 0; f2 < 2; f2++) {
    for (f3 = 0; f3 < 2; f3++) {
      sum = 0LL;
      max = 0LL;
      for (f1 = 0; f1 < L; f1++) {
        temp = std::abs(XY[0][f1] - XY[f2][HL - 1]) +
               std::abs(XY[1][f1] - XY[f3][HL]);
        sum += temp;
        if (temp > max)
          max = temp;
      }
      sum = sum * 2 - max;
      if (sum < osum) {
        osum = sum;
        ox = XY[f2][HL - 1];
        oy = XY[f3][HL];
      }
    }
  }

  std::cout << osum << std::endl;
  std::cout << ox << " " << oy << std::endl;

  return 0;
}