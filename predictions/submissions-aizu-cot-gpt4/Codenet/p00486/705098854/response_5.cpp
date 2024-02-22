#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long w, h, L, HL;
  cin >> w >> h >> L;

  vector<long long> LXY[2], XY[2];
  LXY[0].resize(L);
  LXY[1].resize(L);

  for (int f1 = 0; f1 < L; f1++) {
    cin >> LXY[0][f1] >> LXY[1][f1];
    XY[0].push_back(LXY[0][f1]);
    XY[1].push_back(LXY[1][f1]);
  }

  sort(XY[0].begin(), XY[0].end());
  sort(XY[1].begin(), XY[1].end());

  HL = (L + 1) / 2;
  if (L == 1) {
    cout << 0 << "\n" << LXY[0][0] << " " << LXY[1][0] << "\n";
  } else {
    long long oxy[2][2], ox, oy;
    int dx, dy;
    for (int f1 = 0; f1 < 2; f1++) {
      oxy[0][f1] = XY[f1][HL - 1];
      oxy[1][f1] = XY[f1][HL];
    }
    dx = (oxy[0][0] == oxy[1][0]) ? 1 : 2;
    dy = (oxy[0][1] == oxy[1][1]) ? 1 : 2;
    long long osum = 0, sum;
    for (int f2 = 0; f2 < dx; f2++) {
      for (int f3 = 0; f3 < dy; f3++) {
        sum = 0;
        long long max = 0;
        for (int f1 = 0; f1 < L; f1++) {
          long long temp = abs(LXY[0][f1] - oxy[f2][0]) + abs(LXY[1][f1] - oxy[f3][1]);
          sum += temp;
          if (max < temp)
            max = temp;
        }
        sum = sum * 2 - max;
        if (osum == 0 || osum > sum) {
          osum = sum;
          ox = oxy[f2][0];
          oy = oxy[f3][1];
        }
      }
    }
    cout << osum << "\n" << ox << " " << oy << "\n";
  }
  return 0;
}