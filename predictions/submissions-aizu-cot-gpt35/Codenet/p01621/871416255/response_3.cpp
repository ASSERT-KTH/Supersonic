#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

bool minutes[7 * 24 * 60];

double ck(int start, int m, int t, int s) {
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    int minute = start + (i * t);
    int day = minute / (24 * 60);
    int minuteOfDay = minute % (24 * 60);
    if (minuteOfDay >= 18 * 60 || minuteOfDay < 6 * 60) {
      day++;
    }
    if (!minutes[day * (24 * 60) + minuteOfDay]) {
      return 0.0;
    }
    cnt++;
  }
  return (1.0 - pow(1.0 - 1.0 / s, cnt));
}

int main() {
  int s, n, t, m, p;
  string weekday, time;
  
  while (cin >> s >> n >> t >> weekday >> time >> p >> m, m) {
    int wbits = (weekday == "All") ? ((1 << 7) - 1) : 1;
    int tbits = (time == "Night") ? 1 : ((time == "Day") ? 2 : 3);
    
    for (int i = 0; i < 7 * 24 * 60; i++) {
      int day = i / (24 * 60);
      int minuteOfDay = i % (24 * 60);
      if ((wbits & (1 << day)) && (tbits & (1 << ((minuteOfDay / 360 + 1) % 4 / 2)))) {
        minutes[i] = true;
      } else {
        minutes[i] = false;
      }
    }
    
    double maxProbability = 0.0;
    for (int i = 0; i < 24 * 60; i++) {
      maxProbability = max(maxProbability, ck(i, m, t, s));
      if (maxProbability == 1.0) {
        break;
      }
    }
    
    cout << fixed << setprecision(16) << maxProbability << endl;
  }
}