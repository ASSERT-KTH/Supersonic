#include <bits/stdc++.h>
using namespace std;
bool minutes[10080];
double ck(int m, int t, int s, int n, int p) {
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    bool flag = true;
    for (int j = 0; j <= s; j++) {
      if (!minutes[(i * t + j) % 10080]) {
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
  while (true) {
    int s, n, t, m, p;
    cin >> s >> n >> t >> weekday >> time >> p >> m;
    if (m == 0) break;
    int wbits = (weekday == "All") ? 127 : 1;
    int tbits = (time == "Night") ? 1 : ((time == "Day") ? 2 : 3);
    for (int i = 0; i < 10080; i++) {
      int d = i / 1440;
      int h = i % 1440 / 60;
      bool is_weekday = (d >= 1) && (d <= 5);
      bool is_night = (h >= 18) || (h < 6);
      minutes[i] = (wbits & (1 << d)) && (tbits & (1 << (is_night ? 0 : (is_weekday ? 1 : 2))));
    }
    double ans = 0.0;
    for (int i = 0; i < t; i++) {
      ans = max(ans, ck(m, t, s, n, p));
      for (int j = 0; j < 10080; j++) {
        minutes[j] = minutes[(j + 1) % 10080];
      }
    }
    cout << fixed << setprecision(16) << ans << endl;
  }
}