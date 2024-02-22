#include <cstdio>
#include <vector>

struct Info {
  int mornint_start, morning_end, lunch_start, lunch_end, dinner_start,
      dinner_end;
};

int calc(int hour, int minute) {
  return 60 * hour + minute;
}

int main() {
  int N;
  scanf("%d", &N);

  std::vector<Info> info(N);
  for (int i = 0; i < N; i++) {
    int m_st_h, m_st_m, m_ed_h, m_ed_m, l_st_h, l_st_m, l_ed_h, l_ed_m, d_st_h, d_st_m, d_ed_h, d_ed_m;
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &m_st_h, &m_st_m, &m_ed_h, &m_ed_m, &l_st_h, &l_st_m, &l_ed_h, &l_ed_m, &d_st_h, &d_st_m, &d_ed_h, &d_ed_m);

    info[i].mornint_start = calc(m_st_h, m_st_m);
    info[i].morning_end = calc(m_ed_h, m_ed_m);
    info[i].lunch_start = calc(l_st_h, l_st_m);
    info[i].lunch_end = calc(l_ed_h, l_ed_m);
    info[i].dinner_start = calc(d_st_h, d_st_m);
    info[i].dinner_end = calc(d_ed_h, d_ed_m);
  }

  int ans = 0;
  int numInfos = info.size();
  for (int i = 0; i < numInfos; i++) {
    int tmp = 0;
    for (int j = 0; j < numInfos; j++) {
      if (info[j].mornint_start <= info[i].morning_end &&
          info[j].morning_end >= info[i].mornint_start &&
          info[j].lunch_start <= info[i].lunch_end &&
          info[j].lunch_end >= info[i].lunch_start &&
          info[j].dinner_start <= info[i].dinner_end &&
          info[j].dinner_end >= info[i].dinner_start) {
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