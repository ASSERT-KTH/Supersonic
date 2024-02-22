#include <bits/stdc++.h>
using namespace std;

int s, n, t, m, p;
bool availability[24 * 60];
int wbits, tbits;

double ck(int start) {
  int cnt = 0;
  for (int i = 0; i < m; i++, start += t) {
    bool flag = true;
    for (int j = 0; j <= s; j++) {
      if (!availability[(start + j) % (24 * 60)]) {
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
  while (cin >> s >> n >> t >> weekday >> time >> p >> m, m) {
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

    // Populating the availability array
    for (int i = 0; i < 24 * 60; i++) {
      int day = todays(i);
      int time = totime(i);
      if ((wbits & (1 << day)) && (tbits & (1 << time)))
        availability[i] = true;
      else
        availability[i] = false;
    }

    // Sliding window approach to calculate the maximum probability
    for (int i = 0; i < 24 * 60 - s; i++) {
      double prob = ck(i);
      ans = max(ans, prob);
    }
    cout << fixed << setprecision(16) << ans << endl;
  }
}