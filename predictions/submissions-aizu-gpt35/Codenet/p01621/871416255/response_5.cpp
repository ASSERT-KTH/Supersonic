#include <bits/stdc++.h>
using namespace std;
bool minutes[7 * 24 * 60];
int wbits, tbits;
double ck(int start, int m, int t, int s, int n, int p) {
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
  return (1.0 - pow(1.0 - 1.0 / p, (double)cnt * n));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  string weekday, time;
  int s, n, t, m, p;
  while (cin >> s >> n >> t >> weekday >> time >> p >> m, m) {
    memset(minutes, 0, sizeof(minutes));
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
    for (int i = 7 * 24 * 60 - 1; i >= 0; i--) {
      if ((wbits & (1 << i / 1440)) && (tbits & (1 << ((i / 360 + 1) % 4 / 2))))
        minutes[i] = true;
    }
    for (int i = 0; i < 24 * 60; i++) {
      ans = max(ans, ck(i, m, t, s, n, p));
    }
    cout << fixed << setprecision(16) << ans << endl;
  }
}