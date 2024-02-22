#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>

struct Info {
  const int morning_start, morning_end, lunch_start, lunch_end, dinner_start, dinner_end;
};

int calc(int hour, int minute) {
  return 60 * hour + minute;
}

int main() {
  int N;
  scanf("%d", &N);
  
  std::vector<Info> info(N);
  std::vector<int> morning_starts, morning_ends, lunch_starts, lunch_ends, dinner_starts, dinner_ends;

  for (int i = 0; i < N; i++) {
    int m_st_h, m_st_m, m_ed_h, m_ed_m, l_st_h, l_st_m, l_ed_h, l_ed_m, d_st_h, d_st_m, d_ed_h, d_ed_m;
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &m_st_h, &m_st_m, &m_ed_h, &m_ed_m, &l_st_h, &l_st_m, &l_ed_h, &l_ed_m, &d_st_h, &d_st_m, &d_ed_h, &d_ed_m);
    
    info[i].morning_start = calc(m_st_h, m_st_m);
    info[i].morning_end = calc(m_ed_h, m_ed_m);
    morning_starts.push_back(info[i].morning_start);
    morning_ends.push_back(info[i].morning_end);
    
    info[i].lunch_start = calc(l_st_h, l_st_m);
    info[i].lunch_end = calc(l_ed_h, l_ed_m);
    lunch_starts.push_back(info[i].lunch_start);
    lunch_ends.push_back(info[i].lunch_end);
    
    info[i].dinner_start = calc(d_st_h, d_st_m);
    info[i].dinner_end = calc(d_ed_h, d_ed_m);
    dinner_starts.push_back(info[i].dinner_start);
    dinner_ends.push_back(info[i].dinner_end);
  }
  
  std::sort(morning_starts.begin(), morning_starts.end());
  std::sort(morning_ends.begin(), morning_ends.end());
  std::sort(lunch_starts.begin(), lunch_starts.end());
  std::sort(lunch_ends.begin(), lunch_ends.end());
  std::sort(dinner_starts.begin(), dinner_starts.end());
  std::sort(dinner_ends.begin(), dinner_ends.end());
  
  int max_overlap = 0;
  for (int i = 0; i < N; i++) {
    int tmp = 0;
    for (int j = 0; j < N; j++) {
      if (info[j].morning_start <= morning_ends[i] && info[j].morning_end >= morning_starts[i] &&
          info[j].lunch_start <= lunch_ends[i] && info[j].lunch_end >= lunch_starts[i] &&
          info[j].dinner_start <= dinner_ends[i] && info[j].dinner_end >= dinner_starts[i]) {
        tmp++;
      }
    }
    max_overlap = std::max(max_overlap, tmp);
  }
  
  printf("%d\n", max_overlap);
  return 0;
}