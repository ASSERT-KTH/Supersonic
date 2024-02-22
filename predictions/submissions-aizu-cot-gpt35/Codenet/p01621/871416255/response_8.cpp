#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int s, n, m;
bool minutes[7 * 24 * 60];
int wbits;

double ck(int start) {
  int cnt = 0;
  for (int i = 0; i < m; i++, start += s) {
    bool flag = true;
    for (int j = 0; j <= s; j++) {
      if (!minutes[(start + j) % (7 * 24 * 60)]) {
        flag = false;
        break;
      }
    }
    cnt += flag;
  }
  return (1.0 - pow(1.0 - 1.0 / n, (double)cnt * n));
}

int main() {
  string weekday, time;
  while (cin >> s >> n >> weekday >> time >> m, m) {
    wbits = (weekday == "All") ? (1 << 7) - 1 : 1;
    wbits <<= (time == "Night") ? 1 : ((time == "Day") ? 2 : 3);
    double ans = 0.0;
    for (int i = 7 * 24 * 60 - 1; i >= 0; i--) {
      minutes[i] = wbits & (1 << (i / 1440)) && (1 << (((i / 360) + 1) % 4 / 2));
    }
    for (int i = 24 * 60 - 1; i >= 0; i--) {
      ans = max(ans, ck(i));
    }
    cout << fixed << setprecision(16) << ans << endl;
  }
}