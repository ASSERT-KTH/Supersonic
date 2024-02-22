#include <cstdio>
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

  int m_st_h, m_st_m, m_ed_h, m_ed_m, l_st_h, l_st_m, l_ed_h, l_ed_m, d_st_h,
      d_st_m, d_ed_h, d_ed_m;

  for (int i = 0; i < N; i++) {
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &m_st_h, &m_st_m, &m_ed_h,
          &m_ed_m, &l_st_h, &l_st_m, &l_ed_h, &l_ed_m, &d_st_h, &d_st_m,
          &d_ed_h, &d_ed_m);
    
    info[i].mornint_start = calc(m_st_h, m_st_m);
    info[i].morning_end = calc(m_ed_h, m_ed_m);
    info[i].lunch_start = calc(l_st_h, l_st_m);
    info[i].lunch_end = calc(l_ed_h, l_ed_m);
    info[i].dinner_start = calc(d_st_h, d_st_m);
    info[i].dinner_end = calc(d_ed_h, d_ed_m);
  }

  int ans = 0, tmp;
  for (int a = 0; a < N; a++) {
    for (int b = 0; b < N; b++) {
      for (int c = 0; c < N; c++) {
        tmp = 0;
        for (int i = 0; i < N; i++) {
          if (info[i].mornint_start <= info[a].morning_end &&
              info[i].morning_end >= info[a].mornint_start &&
              info[i].lunch_start <= info[b].lunch_end &&
              info[i].lunch_end >= info[b].lunch_start &&
              info[i].dinner_start <= info[c].dinner_end &&
              info[i].dinner_end >= info[c].dinner_start) {
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