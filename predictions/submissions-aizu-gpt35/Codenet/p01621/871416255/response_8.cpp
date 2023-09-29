#include <bits/stdc++.h>
using namespace std;
const int MAX_MINUTES = 7 * 24 * 60;
bool minutes[MAX_MINUTES];
inline int todays(int i) { return (i / (24 * 60)); }
inline bool totime(int i) {
  int tm = i % (24 * 60) / 24;
  return (tm >= 18 || tm < 6);
}
double ck(int start, int s, int n, int t, int m, int p) {
  int cnt = 0;
  for (int i = 0; i < m; i++, start += t) {
    bool flag = true;
    for (int j = 0; j <= s; j++) {
      if (!minutes[(start + j) % MAX_MINUTES]) {
        flag = false;
        break;
      }
    }
    cnt += flag;
  }
  return (1.0 - pow(1.0 - 1.0 / p, (double)cnt * n));
}
int main() {
  string weekday, time;
  int s, n, t, m, p;
  while (cin >> s >> n >> t >> weekday >> time >> p >> m, m) {
    int wbits = 0, tbits = 0;
    if (weekday == "All")
      wbits = (1 << 7) - 1;
    else
      wbits = 1;
    if (time == "Night")
      tbits = 1;
    else if (time == "Day")
      tbits = 2;
    else
      tbits = 3;
    double ans = 0.0;
    memset(minutes, 0, sizeof(minutes));
    for (int i = MAX_MINUTES - 1; i >= 0; i--) {
      if ((wbits & (1 << i / 1440)) && (tbits & (1 << ((i / 360 + 1) % 4 / 2))))
        minutes[i] = true;
    }
    for (int i = 24 * 60 - 1; i >= 0; i--) {
      ans = max(ans, ck(i, s, n, t, m, p));
    }
    cout << fixed << setprecision(16) << ans << endl;
  }
}