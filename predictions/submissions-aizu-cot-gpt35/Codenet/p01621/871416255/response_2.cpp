#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int s, n, t, m, p;
bool minutes[7 * 24 * 60];

double ck(int start) {
  int cnt = 0;
  int consecutive_minutes = 0;
  for (int i = 0; i < m; i++, start += t) {
    consecutive_minutes = (minutes[start] ? consecutive_minutes + 1 : 0);
    if (consecutive_minutes >= s + 1) {
      cnt++;
      consecutive_minutes = 0;
    }
  }
  return (1.0 - pow(1.0 - 1.0 / p, (double)cnt * n));
}

int main() {
  string weekday, time;
  while (cin >> s >> n >> t >> weekday >> time >> p >> m, m) {
    double ans = 0.0;
    for (int i = 7 * 24 * 60 - 1; i >= 0; i--) {
      if ((weekday == "All" || i % 1440 / 360 == 6) && (time == "Night" || (i % 1440 / 360 + 1) % 4 / 2 == 1)) {
        minutes[i] = true;
      } else {
        minutes[i] = false;
      }
    }
    for (int i = 24 * 60 - 1; i >= 0; i--) {
      ans = max(ans, ck(i));
    }
    cout << fixed << setprecision(16) << ans << endl;
  }
}