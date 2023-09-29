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
  vector<int> MORNING, LUNCH, DINNER;
  int m_st_h, m_st_m, m_ed_h, m_ed_m, l_st_h, l_st_m, l_ed_h, l_ed_m, d_st_h,
      d_st_m, d_ed_h, d_ed_m;
  for (int i = 0; i < N; i++) {
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &m_st_h, &m_st_m, &m_ed_h,
          &m_ed_m, &l_st_h, &l_st_m, &l_ed_h, &l_ed_m, &d_st_h, &d_st_m,
          &d_ed_h, &d_ed_m);
    info[i].mornint_start = calc(m_st_h, m_st_m);
    info[i].morning_end = calc(m_ed_h, m_ed_m);
    MORNING.push_back(info[i].mornint_start);
    MORNING.push_back(info[i].morning_end);
    info[i].lunch_start = calc(l_st_h, l_st_m);
    info[i].lunch_end = calc(l_ed_h, l_ed_m);
    LUNCH.push_back(info[i].lunch_start);
    LUNCH.push_back(info[i].lunch_end);
    info[i].dinner_start = calc(d_st_h, d_st_m);
    info[i].dinner_end = calc(d_ed_h, d_ed_m);
    DINNER.push_back(info[i].dinner_start);
    DINNER.push_back(info[i].dinner_end);
  }
  sort(MORNING.begin(), MORNING.end());
  sort(LUNCH.begin(), LUNCH.end());
  sort(DINNER.begin(), DINNER.end());
  int ans = 0, tmp, a = 0, b = 0, c = 0;
  while (a < MORNING.size() && b < LUNCH.size() && c < DINNER.size()) {
    int m_start = MORNING[a], m_end = info[0].morning_end;
    int l_start = LUNCH[b], l_end = info[0].lunch_end;
    int d_start = DINNER[c], d_end = info[0].dinner_end;
    for (int i = 1; i < N; i++) {
      if (info[i].morning_end < m_end) {
        m_end = info[i].morning_end;
      }
      if (info[i].lunch_end < l_end) {
        l_end = info[i].lunch_end;
      }
      if (info[i].dinner_end < d_end) {
        d_end = info[i].dinner_end;
      }
    }
    tmp = 0;
    for (int i = 0; i < N; i++) {
      if (info[i].mornint_start <= m_start && info[i].morning_end >= m_end &&
          info[i].lunch_start <= l_start && info[i].lunch_end >= l_end &&
          info[i].dinner_start <= d_start && info[i].dinner_end >= d_end) {
        tmp++;
      }
    }
    if (tmp > ans) {
      ans = tmp;
    }
    int min_val = min(m_end, min(l_end, d_end));
    if (min_val == m_end) {
      a++;
    }
    if (min_val == l_end) {
      b++;
    }
    if (min_val == d_end) {
      c++;
    }
  }
  printf("%d\n", ans);
  return 0;
}