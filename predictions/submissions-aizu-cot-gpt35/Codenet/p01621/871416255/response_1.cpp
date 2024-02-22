#include <iostream>
#include <iomanip>
#include <bitset>
#include <vector>
using namespace std;

int s, n, t, m, p;
vector<bool> minutes(7 * 24 * 60);

double ck(int start) {
  int cnt = 0;
  for (int i = 0; i < m; i++, start += t) {
    int end = start + s;
    if (end >= 7 * 24 * 60) {
      end -= 7 * 24 * 60;
      cnt += (end - start + 1) - (minutes.size() - 1 - end + 1);
    } else {
      cnt += (end - start + 1) - (minutes.size() - 1 - end + 1);
    }
  }

  double pow_val = 1.0 - 1.0 / p;
  return (1.0 - pow(pow_val, (double)cnt * n));
}

inline int todays(int i) { return (i / (24 * 60)); }

inline bool totime(int i) {
  int tm = i % (24 * 60) / 24;
  return (tm >= 18 || tm < 6);
}

int main() {
  string weekday, time;
  while (cin >> s >> n >> t >> weekday >> time >> p >> m, m) {
    bitset<7> wbits;
    if (weekday == "All")
      wbits.set();
    else
      wbits.set(0);
    
    bitset<4> tbits;
    if (time == "Night")
      tbits.set(0);
    else if (time == "Day")
      tbits.set(1);
    else
      tbits.set(2);

    double ans = 0.0;

    for (int i = 7 * 24 * 60 - 1; i >= 0; i--) {
      if (wbits[todays(i)] && tbits[((i / 360 + 1) % 4) / 2])
        minutes[i] = true;
      else
        minutes[i] = false;
    }

    for (int i = 24 * 60 - 1; i >= 0; i--) {
      ans = max(ans, ck(i));
    }

    cout << fixed << setprecision(16) << ans << endl;
  }
}