#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main() {
  long long w, h, L, HL;
  long long ox, oy, osum = LLONG_MAX;
  vector<long long> LXY[2], XY[2];
  cin >> w >> h;
  cin >> L;
  for (long long f1 = 0; f1 < L; f1++) {
    cin >> LXY[0][f1] >> LXY[1][f1];
    XY[0].push_back(LXY[0][f1]);
    XY[1].push_back(LXY[1][f1]);
  }
  sort(XY[0].begin(), XY[0].end());
  sort(XY[1].begin(), XY[1].end());
  HL = (L + 1) / 2;
  if (L == 1) {
    cout << "0\n";
    cout << LXY[0][0] << " " << LXY[1][0] << "\n";
  } else {
    long long oxy[2][2] = {{XY[0][HL - 1], XY[1][HL - 1]}, {XY[0][HL], XY[1][HL]}};
    long long dx = (oxy[0][0] == oxy[1][0]) ? 1 : 2;
    long long dy = (oxy[0][1] == oxy[1][1]) ? 1 : 2;
    for (long long f2 = 0; f2 < dx; f2++) {
      for (long long f3 = 0; f3 < dy; f3++) {
        long long sum = 0, max = 0;
        for (long long f1 = 0; f1 < L; f1++) {
          long long temp = abs(LXY[0][f1] - oxy[f2][0]) + abs(LXY[1][f1] - oxy[f3][1]);
          sum += temp;
          if (max < temp)
            max = temp;
        }
        sum = sum * 2 - max;
        if (osum > sum) {
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