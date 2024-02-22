#include <stdio.h>
#include <vector>
using namespace std;

int calc(int hour, int minute) {
  return 60 * hour + minute;
}

int main() {
  int N;
  scanf("%d", &N);
  int m_st_h, m_st_m, m_ed_h, m_ed_m, l_st_h, l_st_m, l_ed_h, l_ed_m, d_st_h,
      d_st_m, d_ed_h, d_ed_m;
  vector<int> INTERVALS;

  for (int i = 0; i < N; i++) {
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &m_st_h, &m_st_m, &m_ed_h,
          &m_ed_m, &l_st_h, &l_st_m, &l_ed_h, &l_ed_m, &d_st_h, &d_st_m,
          &d_ed_h, &d_ed_m);
    INTERVALS.push_back(calc(m_st_h, m_st_m));
    INTERVALS.push_back(calc(m_ed_h, m_ed_m));
    INTERVALS.push_back(calc(l_st_h, l_st_m));
    INTERVALS.push_back(calc(l_ed_h, l_ed_m));
    INTERVALS.push_back(calc(d_st_h, d_st_m));
    INTERVALS.push_back(calc(d_ed_h, d_ed_m));
  }

  sort(INTERVALS.begin(), INTERVALS.end());

  int ans = 0;

  for (int i = 0; i < INTERVALS.size(); i++) {
    int tmp = 0;

    for (int j = 0; j < N; j++) {
      if (INTERVALS[i] >= info[j].mornint_start &&
          INTERVALS[i] <= info[j].morning_end &&
          INTERVALS[i] >= info[j].lunch_start &&
          INTERVALS[i] <= info[j].lunch_end &&
          INTERVALS[i] >= info[j].dinner_start &&
          INTERVALS[i] <= info[j].dinner_end) {
        tmp++;
      }
    }

    if (tmp > ans) {
      ans = tmp;
    }
  }

  printf("%d\n", ans);

  return 0;
}