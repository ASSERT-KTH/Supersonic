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
  int morning_start, morning_end, lunch_start, lunch_end, dinner_start,
      dinner_end;
};
int calc(int hour, int minute) { return 60 * hour + minute; }
int main() {
  int n;
  scanf("%d", &n);
  Info info[n];
  vector<int> morning, lunch, dinner;
  int m_st_h, m_st_m, m_ed_h, m_ed_m, l_st_h, l_st_m, l_ed_h, l_ed_m, d_st_h,
      d_st_m, d_ed_h, d_ed_m;
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &m_st_h, &m_st_m, &m_ed_h,
          &m_ed_m, &l_st_h, &l_st_m, &l_ed_h, &l_ed_m, &d_st_h, &d_st_m,
          &d_ed_h, &d_ed_m);
    info[i].morning_start = calc(m_st_h, m_st_m);
    info[i].morning_end = calc(m_ed_h, m_ed_m);
    morning.push_back(info[i].morning_start);
    morning.push_back(info[i].morning_end);
    info[i].lunch_start = calc(l_st_h, l_st_m);
    info[i].lunch_end = calc(l_ed_h, l_ed_m);
    lunch.push_back(info[i].lunch_start);
    lunch.push_back(info[i].lunch_end);
    info[i].dinner_start = calc(d_st_h, d_st_m);
    info[i].dinner_end = calc(d_ed_h, d_ed_m);
    dinner.push_back(info[i].dinner_start);
    dinner.push_back(info[i].dinner_end);
  }
  sort(morning.begin(), morning.end());
  sort(lunch.begin(), lunch.end());
  sort(dinner.begin(), dinner.end());
  int ans = 0, tmp;
  for (int a = 0; a < morning.size(); a++) {
    for (int b = 0; b < lunch.size(); b++) {
      for (int c = 0; c < dinner.size(); c++) {
        tmp = 0;
        for (int i = 0; i < n; i++) {
          if (info[i].morning_start <= morning[a] &&
              info[i].morning_end >= morning[a] &&
              info[i].lunch_start <= lunch[b] &&
              info[i].lunch_end >= lunch[b] &&
              info[i].dinner_start <= dinner[c] &&
              info[i].dinner_end >= dinner[c]) {
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