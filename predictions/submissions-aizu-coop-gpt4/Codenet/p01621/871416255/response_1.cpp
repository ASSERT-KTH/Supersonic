#include <bits/stdc++.h>
using namespace std;
int s, n, t, m, p;
bool minutes[7 * 24 * 60];
int wbits, tbits;

double ck(int start, vector<int>& prefixSum) {
  int cnt = prefixSum[(start + s) % (7 * 24 * 60)] - prefixSum[start];
  return (1.0 - pow(1.0 - 1.0 / p, (double)cnt * n));
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
    vector<int> prefixSum(7 * 24 * 60 + 1, 0);
    for (int i = 7 * 24 * 60 - 1; i >= 0; i--) {
      if ((wbits & (1 << i / 1440)) && (tbits & (1 << ((i / 360 + 1) % 4 / 2))))
        minutes[i] = true;
      else
        minutes[i] = false;
      prefixSum[i] = prefixSum[i + 1] + minutes[i];
    }
    prefixSum[0] = prefixSum[1];
    for (int i = 24 * 60 - 1; i >= 0; i--) {
      ans = max(ans, ck(i, prefixSum));
    }
    cout << fixed << setprecision(16) << ans << endl;
  }
}