#include <iostream>
#include <bitset>
#include <iomanip>
using namespace std;

constexpr int MINUTES_PER_WEEK = 7 * 24 * 60;

bitset<MINUTES_PER_WEEK> minutes;
int s, n, t, m, p;
int wbits, tbits;
double precalculated_pow;

double ck(int start) {
  int cnt = 0;
  for (int i = 0; i < m; i++, start += t) {
    bool flag = true;
    for (int j = 0; j <= s; j++) {
      if (!minutes[(start + j) % MINUTES_PER_WEEK]) {
        flag = false;
        break;
      }
    }
    cnt += flag;
  }
  return (1.0 - precalculated_pow * (double)cnt * n);
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

    // Precalculate pow
    precalculated_pow = 1.0 - 1.0 / p;

    // Initialize minutes bitset
    minutes.reset();
    for (int i = 0; i < MINUTES_PER_WEEK; i++) {
      if ((wbits & (1 << todays(i))) && (tbits & (1 << ((i / 360 + 1) % 4 / 2))))
        minutes.set(i);
    }

    for (int i = 24 * 60 - 1; i >= 0; i--) {
      ans = max(ans, ck(i));
    }
    cout << fixed << setprecision(16) << ans << endl;
  }
}