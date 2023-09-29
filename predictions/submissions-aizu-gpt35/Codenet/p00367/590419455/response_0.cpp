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
#include <bitset>

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
    info[i].mornint_start = 60 * m_st_h + m_st_m;
    info[i].morning_end = 60 * m_ed_h + m_ed_m;
    MORNING.push_back(info[i].mornint_start);
    MORNING.push_back(info[i].morning_end);
    info[i].lunch_start = 60 * l_st_h + l_st_m;
    info[i].lunch_end = 60 * l_ed_h + l_ed_m;
    LUNCH.push_back(info[i].lunch_start);
    LUNCH.push_back(info[i].lunch_end);
    info[i].dinner_start = 60 * d_st_h + d_st_m;
    info[i].dinner_end = 60 * d_ed_h + d_ed_m;
    DINNER.push_back(info[i].dinner_start);
    DINNER.push_back(info[i].dinner_end);
  }
  sort(MORNING.begin(), MORNING.end());
  sort(LUNCH.begin(), LUNCH.end());
  sort(DINNER.begin(), DINNER.end());
  int ans = 0, tmp;
  for (int a = 0; a < MORNING.size(); a++) {
    for (int b = 0; b < LUNCH.size(); b++) {
      for (int c = 0; c < DINNER.size(); c++) {
        tmp = 0;
        bitset<50> enabled;
        for (int i = 0; i < N; i++) {
          if (info[i].mornint_start <= MORNING[a] &&
              info[i].morning_end >= MORNING[a] &&
              info[i].lunch_start <= LUNCH[b] &&
              info[i].lunch_end >= LUNCH[b] &&
              info[i].dinner_start <= DINNER[c] &&
              info[i].dinner_end >= DINNER[c]) {
            enabled.set(i);
          }
        }
        if (enabled.count() > ans) {
          ans = enabled.count();
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
