#include <bits/stdc++.h>
using namespace std;
int s, n, t, m, p;
bool minutes[7 * 24 * 60];
int wbits, tbits;
double ans[7 * 24 * 60]; // cache results

double ck(int start) {
  if (ans[start] != -1) return ans[start]; // use cached result if exists
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
  return ans[start] = (1.0 - pow(1.0 - 1.0 / p, (double)cnt * n)); // cache result
}

int main() {
  string weekday, time;
  while (cin >> s >> n >> t >> weekday >> time >> p >> m, m) {
    if (weekday == "All")
      wbits = 7;
    else
      wbits = 1;
    if (time == "Night")
      tbits = 1;
    else if (time == "Day")
      tbits = 2;
    else
      tbits = 3;
    double max_ans = 0.0;
    for (int i = 7 * 24 * 60 - 1; i >= 0; i--) {
      if (minutes[i] && !((wbits & (1 << i / 1440)) && (tbits & (1 << ((i / 360 + 1) % 4 / 2))))) 
        minutes[i] = false;
      else
        minutes[i] = true;
      ans[i] = -1; // initialize cache with -1
    }
    for (int i = 24 * 60 - 1; i >= 0; i--) {
      max_ans = max(max_ans, ck(i));
    }
    cout << fixed << setprecision(16) << max_ans << endl;
  }
}