#include <bits/stdc++.h>
using namespace std;
const int MAX_MINUTES = 7 * 24 * 60;
int s, n, t, m, p;
bool minutes[MAX_MINUTES];
double ck(int start) {
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
inline int todays(int i) { return (i / (24 * 60)); }
inline bool totime(int i) {
  int tm = i % (24 * 60) / 24;
  return (tm >= 18 || tm < 6);
}
int main() {
  string weekday, time;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  while (cin >> s >> n >> t >> weekday >> time >> p >> m, m) {
    int wbits = 0;
    if (weekday == "All")
      wbits = (1 << 7) - 1;
    else
      wbits = 1 << (weekday[0] - 'A');
    int tbits = 0;
    if (time == "Day")
      tbits = 2;
    else if (time == "Night")
      tbits = 1;
    double ans = 0.0;
    memset(minutes, false, sizeof(minutes));
    for (int i = 0; i < MAX_MINUTES; i += 1440) {
      if ((wbits & (1 << i / 1440))) {
        for (int j = i + ((tbits & 1) ? 1080 : 420); j < i + ((tbits & 1) ? 1440 : 1080); j++)
          minutes[j % MAX_MINUTES] = true;
        for (int j = i + ((tbits & 2) ? 0 : 1080); j < i + ((tbits & 2) ? 420 : 1440); j++)
          minutes[j % MAX_MINUTES] = true;
      }
    }
    for (int i = 0; i < 1440; i++) {
      ans = max(ans, ck(i));
    }
    cout << fixed << setprecision(16) << ans << '\n';
  }
}