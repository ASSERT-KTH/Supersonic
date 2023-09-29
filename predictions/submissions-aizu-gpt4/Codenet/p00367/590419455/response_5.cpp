#include <vector>
#include <algorithm>
#include <stdio.h>

struct Info {
  int mornint_start, morning_end, lunch_start, lunch_end, dinner_start, dinner_end;
};

inline int calc(int hour, int minute) { return 60 * hour + minute; }

int main() {
  int N;
  scanf("%d", &N);
  std::vector<Info> info(N);

  for (auto& i : info) {
    int m_st_h, m_st_m, m_ed_h, m_ed_m, l_st_h, l_st_m, l_ed_h, l_ed_m, d_st_h, d_st_m, d_ed_h, d_ed_m;
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &m_st_h, &m_st_m, &m_ed_h, &m_ed_m, &l_st_h, &l_st_m, &l_ed_h, &l_ed_m, &d_st_h, &d_st_m, &d_ed_h, &d_ed_m);
    i.mornint_start = calc(m_st_h, m_st_m);
    i.morning_end = calc(m_ed_h, m_ed_m);
    i.lunch_start = calc(l_st_h, l_st_m);
    i.lunch_end = calc(l_ed_h, l_ed_m);
    i.dinner_start = calc(d_st_h, d_st_m);
    i.dinner_end = calc(d_ed_h, d_ed_m);
  }

  int ans = 0;

  for (const auto& a : info) {
    for (const auto& b : info) {
      if (b.mornint_start < a.morning_end) continue;
      for (const auto& c : info) {
        if (c.lunch_start < b.morning_end || c.dinner_start < c.lunch_end) continue;
        int tmp = 0;
        for (const auto& i : info) {
          if (i.mornint_start <= a.morning_end && i.morning_end >= a.morning_end && i.lunch_start <= b.lunch_end && i.lunch_end >= b.lunch_end && i.dinner_start <= c.dinner_end && i.dinner_end >= c.dinner_end) {
            ++tmp;
          }
        }
        ans = std::max(ans, tmp);
      }
    }
  }

  printf("%d\n", ans);
  return 0;
}