#include <bits/stdc++.h>
using namespace std;
const int MAX_MINUTES = 10080; // 7*24*60
bool minutes[MAX_MINUTES];
double ck(int start, int m, int t, int s, int p, int n) {
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
      wbits = 1 << (weekday[0] - 'A');
    if (time == "Night")
      tbits = 1;
    else if (time == "Day")
      tbits = 2;
    else
      tbits = 3;
    memset(minutes, false, sizeof(minutes));
    for (int i = 0; i < MAX_MINUTES; i++) {
      if ((wbits & (1 << (i / 1440))) && (tbits & (1 << ((i / 360 + 1) % 4 / 2))))
        minutes[i] = true;
    }
    double ans = 0.0;
    for (int i = 0; i < 24 * 60; i++) {
      ans = max(ans, ck(i, m, t, s, p, n));
    }
    cout << fixed << setprecision(16) << ans << endl;
  }
}