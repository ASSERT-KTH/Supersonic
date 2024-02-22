#include <bits/stdc++.h>
using namespace std;
int s, n, t, m, p;
bool minutes[7 * 24 * 60];
int prefixSum[7 * 24 * 60];
int wbits, tbits;
double preCalcPow[50005];
double ck(int start) {
  int cnt = 0;
  for (int i = 0; i < m; i++, start += t) {
    int end = (start + s) % (7 * 24 * 60);
    int sum = prefixSum[end] - (start > 0 ? prefixSum[start - 1] : 0) + (start <= end ? 0 : prefixSum[7*24*60 - 1]);
    if (sum == s + 1)
      cnt++;
  }
  return preCalcPow[cnt * n];
}
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
    for (int i = 0; i < 7 * 24 * 60; i++) {
      if ((wbits & (1 << i / 1440)) && (tbits & (1 << ((i / 360 + 1) % 4 / 2))))
        minutes[i] = true;
      else
        minutes[i] = false;
      prefixSum[i] = minutes[i] + (i > 0 ? prefixSum[i - 1] : 0);
    }
    for (int i = 0; i <= m * n; i++) {
      preCalcPow[i] = 1.0 - pow(1.0 - 1.0 / p, i);
    }
    for (int i = 24 * 60 - 1; i >= 0; i--) {
      ans = max(ans, ck(i));
    }
    cout << fixed << setprecision(16) << ans << endl;
  }
}