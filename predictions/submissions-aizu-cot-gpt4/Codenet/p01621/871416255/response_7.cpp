#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>

using namespace std;

int s, n, t, m, p;
bool minutes[7 * 24 * 60];
int wbits, tbits;

double ck(int start) {
  int cnt = 0;
  for (int i = 0; i < m; i++, start += t) {
    for (int j = 0; j <= s; j++) {
      if (!minutes[(start + j) % (7 * 24 * 60)]) {
        break;
      }
      if (j == s) {
        cnt++;
      }
    }
  }
  return (1.0 - pow(1.0 / p, cnt * n));
}

int main() {
  string weekday, time;
  while (cin >> s >> n >> t >> weekday >> time >> p >> m, m) {
    if (weekday == "All") {
      wbits = (1 << 7) - 1;
    } else {
      wbits = 1;
    }
    if (time == "Night") {
      tbits = 1;
    } else if (time == "Day") {
      tbits = 2;
    } else {
      tbits = 3;
    }
    memset(minutes, false, sizeof(minutes));
    for (int i = 7 * 24 * 60 - 1; i >= 0; i--) {
      if ((wbits & (1 << i / 1440)) && (tbits & (1 << ((i / 360 + 1) % 4 / 2)))) {
        minutes[i] = true;
      }
    }
    double ans = 0.0;
    for (int i = 24 * 60 - 1; i >= 0; i--) {
      ans = max(ans, ck(i));
    }
    cout << fixed << setprecision(16) << ans << endl;
  }
  return 0;
}