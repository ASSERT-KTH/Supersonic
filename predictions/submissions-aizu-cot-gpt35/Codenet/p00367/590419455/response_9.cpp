#include <algorithm>
#include <iostream>
#include <set>
#include <stdio.h>
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
  vector<Info> info(N);
  set<int> MORNING, LUNCH, DINNER;
  int m_st_h, m_st_m, m_ed_h, m_ed_m, l_st_h, l_st_m, l_ed_h, l_ed_m, d_st_h,
      d_st_m, d_ed_h, d_ed_m;
  for (int i = 0; i < N; i++) {
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &m_st_h, &m_st_m, &m_ed_h,
          &m_ed_m, &l_st_h, &l_st_m, &l_ed_h, &l_ed_m, &d_st_h, &d_st_m,
          &d_ed_h, &d_ed_m);
    info[i].mornint_start = calc(m_st_h, m_st_m);
    info[i].morning_end = calc(m_ed_h, m_ed_m);
    MORNING.insert(info[i].mornint_start);
    MORNING.insert(info[i].morning_end);
    info[i].lunch_start = calc(l_st_h, l_st_m);
    info[i].lunch_end = calc(l_ed_h, l_ed_m);
    LUNCH.insert(info[i].lunch_start);
    LUNCH.insert(info[i].lunch_end);
    info[i].dinner_start = calc(d_st_h, d_st_m);
    info[i].dinner_end = calc(d_ed_h, d_ed_m);
    DINNER.insert(info[i].dinner_start);
    DINNER.insert(info[i].dinner_end);
  }
  int ans = 0, tmp;
  for (int i = 0; i < N; i++) {
    tmp = 0;
    for (auto morning : MORNING) {
      for (auto lunch : LUNCH) {
        for (auto dinner : DINNER) {
          if (info[i].mornint_start <= morning &&
              info[i].morning_end >= morning &&
              info[i].lunch_start <= lunch &&
              info[i].lunch_end >= lunch &&
              info[i].dinner_start <= dinner &&
              info[i].dinner_end >= dinner) {
            tmp++;
          }
        }
      }
    }
    if (tmp > ans) {
      ans = tmp;
    }
  }
  printf("%d\n", ans);
  return 0;
}