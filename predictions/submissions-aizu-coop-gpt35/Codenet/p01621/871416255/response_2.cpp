#include <bits/stdc++.h>
using namespace std;

const int MAX_MINUTES = 7 * 24 * 60;

int s, n, t, m, p;
bitset<MAX_MINUTES> minutes;
vector<int> available(MAX_MINUTES);

double ck(int start) {
  int cnt = 0;
  for (int i = 0; i < m; i++, start += t) {
    if (available[(start + s) % MAX_MINUTES] - available[start % MAX_MINUTES] == s + 1) {
      cnt++;
    }
  }
  return (1.0 - pow(1.0 - 1.0 / p, (double)cnt * n));
}

inline int todays(int i) {
  return (i / (24 * 60));
}

inline bool totime(int i) {
  int tm = i % (24 * 60) / 24;
  return (tm >= 18 || tm < 6);
}

int main() {
  string weekday, time;
  while (cin >> s >> n >> t >> weekday >> time >> p >> m, m) {
    if (weekday == "All")
      minutes.set();
    else
      minutes.reset();
    if (time == "Night")
      minutes.set(0, MAX_MINUTES, false);
    else if (time == "Day")
      minutes.set(0, MAX_MINUTES, true);
    else {
      minutes.set(0, MAX_MINUTES, true);
      minutes.set(0, 6 * 60, false);
      minutes.set(18 * 60, 24 * 60, false);
    }

    for (int i = 1; i < MAX_MINUTES; i++) {
      available[i] = available[i - 1] + minutes[i - 1];
    }

    double ans = 0.0;
    for (int i = 24 * 60 - 1; i >= 0; i--) {
      ans = max(ans, ck(i));
    }
    cout << fixed << setprecision(16) << ans << endl;
  }
}