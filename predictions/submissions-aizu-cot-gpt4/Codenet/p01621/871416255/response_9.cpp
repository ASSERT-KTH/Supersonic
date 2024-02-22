#include <bits/stdc++.h>
using namespace std;

int s, n, t, m, p, wbits, tbits;
bool minutes[7 * 24 * 60];
double powers[7 * 24 * 60];
const int WEEK_MINUTES = 7 * 24 * 60;

double ck(int start) {
  int cnt = 0;
  for (int i = 0; i < m; i++, start += t) {
    bool flag = true;
    for (int j = 0; j <= s; j++) {
      if (!minutes[(start + j) % WEEK_MINUTES]) {
        flag = false;
        break;
      }
    }
    cnt += flag;
  }
  return powers[cnt * n];
}

int main() {
  string weekday, time;
  for (int i = 0; i < WEEK_MINUTES; i++)
    powers[i] = (1.0 - pow(1.0 - 1.0 / p, (double)i));
  while (cin >> s >> n >> t >> weekday >> time >> p >> m, m) {
    if (weekday == "All")
      wbits = 7;
    else
      wbits = 1;
    if (time == "Night")
      tbits = 1;
    else if (time == "Day")
      tbits = 2;
    else
      tbits = 3;
    double ans = 0.0;
    for (int i = WEEK_MINUTES - 1; i >= 0; i--) {
      if ((wbits & (i / 1440)) && (tbits & (i / 360 + 1) % 4 / 2))
        minutes[i] = true;
      else
        minutes[i] = false;
    }
    for (int i = 24 * 60 - 1; i >= 0; i--) {
      ans = max(ans, ck(i));
    }
    cout << fixed << setprecision(16) << ans << '\n';
  }
}