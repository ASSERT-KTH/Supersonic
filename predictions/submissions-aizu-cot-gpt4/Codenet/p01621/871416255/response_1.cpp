#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <array>
#include <iomanip>

using namespace std;

double ck(int start, int s, int m, int t, int p, int n, array<bool, 7 * 24 * 60>& minutes) {
  int cnt = 0;
  for (int i = 0; i < m; i++, start += t) {
    bool flag = true;
    for (int j = 0; j <= s; j++) {
      if (!minutes[(start + j) % (7 * 24 * 60)]) {
        flag = false;
        break;
      }
    }
    cnt += flag;
  }
  double result = 1.0;
  for (int i = 0; i < cnt * n; i++) {
    result *= (1.0 - 1.0 / p);
  }
  return (1.0 - result);
}

int main() {
  int s, n, t, m, p;
  string weekday, time;
  while (cin >> s >> n >> t >> weekday >> time >> p >> m, m) {
    int wbits = (weekday == "All") ? (1 << 7) - 1 : 1;
    int tbits = (time == "Night") ? 1 : (time == "Day") ? 2 : 3;
    array<bool, 7 * 24 * 60> minutes;
    fill(minutes.begin(), minutes.end(), false);
    for (int i = 7 * 24 * 60 - 1; i >= 0; i--) {
      if ((wbits & (1 << i / 1440)) && (tbits & (1 << ((i / 360 + 1) % 4 / 2))))
        minutes[i] = true;
    }
    double ans = 0.0;
    for (int i = 24 * 60 - 1; i >= 0; i--) {
      ans = max(ans, ck(i, s, m, t, p, n, minutes));
    }
    cout << fixed << setprecision(16) << ans << endl;
  }
}