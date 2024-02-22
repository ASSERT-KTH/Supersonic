#include <bits/stdc++.h>
using namespace std;

int s, n, t, m, p;
bitset<7 * 24 * 60> minutes;
int wbits, tbits;

double ck(int start) {
  int cnt = 0;
  double prob = 1.0 - 1.0 / p;
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
  double result = 1.0;
  for(int i = 0; i < cnt * n; ++i){
    result *= prob;
  }
  return 1.0 - result;
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
    for (int i = 7 * 24 * 60 - 1; i >= 0; i--) {
      minutes[i] = (wbits & (1 << i / 1440)) && (tbits & (1 << ((i / 360 + 1) % 4 / 2)));
    }
    for (int i = 24 * 60 - 1; i >= 0; i--) {
      ans = max(ans, ck(i));
    }
    cout << fixed << setprecision(16) << ans << endl;
    minutes.reset();
  }
}