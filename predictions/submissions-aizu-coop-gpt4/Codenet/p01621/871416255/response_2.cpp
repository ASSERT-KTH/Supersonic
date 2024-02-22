#include <bits/stdc++.h>
using namespace std;

const int N = 7 * 24 * 60;
double prob[10005]; // Pre-computed values of the power function
int s, n, t, m, p, wbits, tbits;
int cnt[N]; // Count of valid minutes for each minute

double ck(int start) {
  return prob[cnt[start]]; // O(1)
}

inline int todays(int i) { return (i / (24 * 60)); }
inline bool totime(int i) {
  int tm = i % (24 * 60) / 24;
  return (tm >= 18 || tm < 6);
}

int main() {
  string weekday, time;

  // Pre-compute the power function
  for (int i = 0; i <= 10000; i++) {
    prob[i] = 1.0 - pow(1.0 - 1.0 / p, (double)i * n);
  }

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

    // Pre-calculate bitwise operations
    int w[N] = {}, tt[N] = {};
    for (int i = N - 1; i >= 0; i--) {
      w[i] = wbits & (1 << i / 1440);
      tt[i] = tbits & (1 << ((i / 360 + 1) % 4 / 2));
    }

    // Calculate the count of valid minutes for each minute using a sliding window approach
    memset(cnt, 0, sizeof(cnt));
    int valid = 0;
    for (int i = 0; i < m; i++) {
      valid += w[i] && tt[i];
    }
    cnt[m - 1] = valid;
    for (int i = m; i < N; i++) {
      valid = valid - (w[i - m] && tt[i - m]) + (w[i] && tt[i]);
      cnt[i] = valid;
    }

    double ans = 0.0;
    for (int i = N - 1; i >= 0; i--) {
      ans = max(ans, ck(i)); // O(1)
    }
    cout << fixed << setprecision(16) << ans << endl;
  }

  return 0;
}