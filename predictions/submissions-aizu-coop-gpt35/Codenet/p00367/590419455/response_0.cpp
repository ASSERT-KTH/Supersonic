#include <algorithm>
#include <cfloat>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <time.h>
#include <vector>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;
struct Info {
  int mornint_start, morning_end, lunch_start, lunch_end, dinner_start,
      dinner_end;
};
int calc(int hour, int minute) { return 60 * hour + minute; }
int main() {
  int N;
  scanf("%d", &N);
  Info info[N];
  vector<pair<int, int>> times;

  int m_st_h, m_st_m, m_ed_h, m_ed_m, l_st_h, l_st_m, l_ed_h, l_ed_m, d_st_h,
      d_st_m, d_ed_h, d_ed_m;
  for (int i = 0; i < N; i++) {
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &m_st_h, &m_st_m, &m_ed_h,
          &m_ed_m, &l_st_h, &l_st_m, &l_ed_h, &l_ed_m, &d_st_h, &d_st_m,
          &d_ed_h, &d_ed_m);
    info[i].mornint_start = calc(m_st_h, m_st_m);
    info[i].morning_end = calc(m_ed_h, m_ed_m);
    times.push_back(make_pair(info[i].mornint_start, info[i].morning_end));

    info[i].lunch_start = calc(l_st_h, l_st_m);
    info[i].lunch_end = calc(l_ed_h, l_ed_m);
    times.push_back(make_pair(info[i].lunch_start, info[i].lunch_end));

    info[i].dinner_start = calc(d_st_h, d_st_m);
    info[i].dinner_end = calc(d_ed_h, d_ed_m);
    times.push_back(make_pair(info[i].dinner_start, info[i].dinner_end));
  }

  sort(times.begin(), times.end());

  int ans = 0, tmp;
  for (int a = 0; a < times.size(); a++) {
    for (int b = 0; b < times.size(); b++) {
      for (int c = 0; c < times.size(); c++) {
        tmp = 0;
        for (int i = 0; i < N; i++) {
          if (info[i].mornint_start <= times[a].first &&
              info[i].morning_end >= times[a].second &&
              info[i].lunch_start <= times[b].first &&
              info[i].lunch_end >= times[b].second &&
              info[i].dinner_start <= times[c].first &&
              info[i].dinner_end >= times[c].second) {
            tmp++;
          }
        }
        if (tmp > ans) {
          ans = tmp;
        }
      }
    }
  }

  printf("%d\n", ans);
  return 0;
}