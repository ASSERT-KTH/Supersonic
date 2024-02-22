#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
struct Info {
  int morning_start, morning_end;
  int lunch_start, lunch_end;
  int dinner_start, dinner_end;
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
    info[i].morning_start = calc(m_st_h, m_st_m);
    info[i].morning_end = calc(m_ed_h, m_ed_m);
    info[i].lunch_start = calc(l_st_h, l_st_m);
    info[i].lunch_end = calc(l_ed_h, l_ed_m);
    info[i].dinner_start = calc(d_st_h, d_st_m);
    info[i].dinner_end = calc(d_ed_h, d_ed_m);
  }
  sort(info, info + N, [](const Info &a, const Info &b) {
    return a.morning_end < b.morning_end;
  });
  int ans = 0, end_time = 0;
  for (int i = 0; i < N; i++) {
    if (info[i].morning_start >= end_time) {
      end_time = info[i].morning_end;
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}