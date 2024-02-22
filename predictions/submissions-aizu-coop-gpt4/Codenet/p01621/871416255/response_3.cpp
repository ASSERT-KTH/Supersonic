#include <bits/stdc++.h>
using namespace std;

int s, n, t, m, p;
bool minutes[7 * 24 * 60];
int wbits, tbits;
double ck_values[7 * 24];

double ck(int start) {
  int cnt = 0;
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
  return (1.0 - pow(1.0 - 1.0 / p, (double)cnt * n));
}

int main() {
  string weekday, time;
  while (cin >> s >> n >> t >> weekday >> time >> p >> m, m) {
    memset(minutes, false, sizeof(minutes)); // reset minutes array
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
    for (int i = 7 * 24 - 1; i >= 0; i--) {
      bool state = (wbits & (1 << i / 1440)) && (tbits & (1 << ((i / 360 + 1) % 4 / 2)));
      fill_n(&minutes[i*60], 60, state);
    }
    for (int i = 24 - 1; i >= 0; i--) {
      ck_values[i] = ck(i*60); // calculate ck once per day
    }
    double ans = *max_element(ck_values, ck_values + 24);
    cout << fixed << setprecision(16) << ans << endl;
  }
}