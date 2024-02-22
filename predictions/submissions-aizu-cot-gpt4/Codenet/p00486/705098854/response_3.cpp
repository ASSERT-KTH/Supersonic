#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <cmath>
using namespace std;
int main() {
  long long sum = 0LL, osum = 0LL;
  long long f1, f2, f3, L, HL, temp, oxy[2][2], ox, oy, max = 0, dx, dy;
  array<vector<long long>, 2> XY;
  array<array<long long, 2>, 2> LXY;
  cin >> L;
  for (f1 = 0; f1 < L; f1++) {
    cin >> LXY[0][f1] >> LXY[1][f1];
    XY[0].emplace_back(LXY[0][f1]);
    XY[1].emplace_back(LXY[1][f1]);
  }
  sort(XY[0].begin(), XY[0].end());
  sort(XY[1].begin(), XY[1].end());
  HL = (L + 1) / 2;
  if (L == 1) {
    cout << "0\n";
    cout << LXY[0][0] << " " << LXY[1][0] << "\n";
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
          temp = abs(LXY[0][f1] - oxy[f2][0]) +
                 abs(LXY[1][f1] - oxy[f3][1]);
          sum += temp;
          max = max < temp ? temp : max;
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
    cout << osum << "\n";
    cout << ox << " " << oy << "\n";
  }
  return 0;
}