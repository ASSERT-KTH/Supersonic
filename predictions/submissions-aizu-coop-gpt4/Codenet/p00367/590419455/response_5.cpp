#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long int ll;

int calc(int hour, int minute) { return 60 * hour + minute; }

int main() {
  int N;
  scanf("%d", &N);
  map<int, int> MORNING, LUNCH, DINNER;
  vector<int> morn_start(N), morn_end(N), lunch_start(N), lunch_end(N), dinner_start(N), dinner_end(N);
  for (int i = 0; i < N; i++) {
    int m_st_h, m_st_m, m_ed_h, m_ed_m, l_st_h, l_st_m, l_ed_h, l_ed_m, d_st_h, d_st_m, d_ed_h, d_ed_m;
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &m_st_h, &m_st_m, &m_ed_h,
          &m_ed_m, &l_st_h, &l_st_m, &l_ed_h, &l_ed_m, &d_st_h, &d_st_m,
          &d_ed_h, &d_ed_m);
    morn_start[i] = calc(m_st_h, m_st_m);
    morn_end[i] = calc(m_ed_h, m_ed_m);
    lunch_start[i] = calc(l_st_h, l_st_m);
    lunch_end[i] = calc(l_ed_h, l_ed_m);
    dinner_start[i] = calc(d_st_h, d_st_m);
    dinner_end[i] = calc(d_ed_h, d_ed_m);
    MORNING[morn_start[i]]++;
    MORNING[morn_end[i]]--;
    LUNCH[lunch_start[i]]++;
    LUNCH[lunch_end[i]]--;
    DINNER[dinner_start[i]]++;
    DINNER[dinner_end[i]]--;
  }
  int max_overlap = 0, overlap_morning = 0, overlap_lunch = 0, overlap_dinner = 0;
  for(auto &m : MORNING) {
    overlap_morning += m.second;
    for(auto &l : LUNCH) {
      if(l.first < m.first) continue;
      overlap_lunch += l.second;
      for(auto &d : DINNER) {
        if(d.first < l.first) continue;
        overlap_dinner += d.second;
        max_overlap = max(max_overlap, min({overlap_morning, overlap_lunch, overlap_dinner}));
        overlap_dinner -= d.second;
      }
      overlap_lunch -= l.second;
    }
    overlap_morning -= m.second;
  }
  printf("%d\n", max_overlap);
  return 0;
}