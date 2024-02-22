#include <algorithm>
#include <iostream>
#include <stdio.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;
struct Info {
  int morning_start, morning_end, lunch_start, lunch_end, dinner_start, dinner_end;
};
int calc(int hour, int minute) { return 60 * hour + minute; }
int main() {
  int N;
  scanf("%d", &N);
  Info info[N];
  int MORNING[24*60+1] = {0}, LUNCH[24*60+1] = {0}, DINNER[24*60+1] = {0}; // replace vectors with arrays
  int m_st_h, m_st_m, m_ed_h, m_ed_m, l_st_h, l_st_m, l_ed_h, l_ed_m, d_st_h, d_st_m, d_ed_h, d_ed_m;
  for (int i = 0; i < N; i++) {
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &m_st_h, &m_st_m, &m_ed_h, &m_ed_m, &l_st_h, &l_st_m, &l_ed_h, &l_ed_m, &d_st_h, &d_st_m, &d_ed_h, &d_ed_m);
    info[i].morning_start = calc(m_st_h, m_st_m);
    info[i].morning_end = calc(m_ed_h, m_ed_m);
    info[i].lunch_start = calc(l_st_h, l_st_m);
    info[i].lunch_end = calc(l_ed_h, l_ed_m);
    info[i].dinner_start = calc(d_st_h, d_st_m);
    info[i].dinner_end = calc(d_ed_h, d_ed_m);
    // Use histogram method to record the time at which a person starts or ends lunch, dinner or morning
    for(int t = info[i].morning_start; t <= info[i].morning_end; t++) MORNING[t]++;
    for(int t = info[i].lunch_start; t <= info[i].lunch_end; t++) LUNCH[t]++;
    for(int t = info[i].dinner_start; t <= info[i].dinner_end; t++) DINNER[t]++;
  }
  int ans = 0;
  // Calculate the number of people at the same time for each time
  for(int t = 0; t <= 24*60; t++) {
    ans = max(ans, min({MORNING[t], LUNCH[t], DINNER[t]}));
  }
  printf("%d\n", ans);
  return 0;
}