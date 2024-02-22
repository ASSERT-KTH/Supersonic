#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

bool minutes[7 * 24 * 60];

double calculateProbability(int start, int s, int n, int t, int m, int p) {
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
  return (1.0 - exp(log(1.0 - 1.0 / p) * cnt * n));
}

int main() {
  string weekday, time;
  while (cin >> s >> n >> t >> weekday >> time >> p >> m, m) {
    int wbits = (weekday == "All") ? ((1 << 7) - 1) : 1;
    int tbits = (time == "Night") ? 1 : ((time == "Day") ? 2 : 3);

    double maxProbability = 0.0;
    for (int i = 7 * 24 * 60 - 1; i >= 0; i--) {
      if ((wbits & (1 << (i / 1440))) && (tbits & (1 << ((i / 360 + 1) % 4 / 2))))
        minutes[i] = true;
      else
        minutes[i] = false;
    }

    for (int i = 24 * 60 - 1; i >= 0; i--) {
      maxProbability = max(maxProbability, calculateProbability(i, s, n, t, m, p));
    }

    cout << fixed << setprecision(16) << maxProbability << endl;
  }
}