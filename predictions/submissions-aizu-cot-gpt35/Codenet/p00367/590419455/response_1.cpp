#include <algorithm>
#include <iostream>
#include <vector>

struct Info {
  int morning_start, morning_end, lunch_start, lunch_end, dinner_start,
      dinner_end;
};

int calc(int hour, int minute) { return 60 * hour + minute; }

int main() {
  int N;
  std::cin >> N;
  std::vector<Info> info(N);
  std::vector<std::pair<int, int>> intervals;
  
  int m_st_h, m_st_m, m_ed_h, m_ed_m, l_st_h, l_st_m, l_ed_h, l_ed_m, d_st_h,
      d_st_m, d_ed_h, d_ed_m;
  for (int i = 0; i < N; i++) {
    std::cin >> m_st_h >> m_st_m >> m_ed_h >> m_ed_m >> l_st_h >> l_st_m >>
        l_ed_h >> l_ed_m >> d_st_h >> d_st_m >> d_ed_h >> d_ed_m;
    info[i].morning_start = calc(m_st_h, m_st_m);
    info[i].morning_end = calc(m_ed_h, m_ed_m);
    info[i].lunch_start = calc(l_st_h, l_st_m);
    info[i].lunch_end = calc(l_ed_h, l_ed_m);
    info[i].dinner_start = calc(d_st_h, d_st_m);
    info[i].dinner_end = calc(d_ed_h, d_ed_m);
    
    intervals.push_back({info[i].morning_start, info[i].morning_end});
    intervals.push_back({info[i].lunch_start, info[i].lunch_end});
    intervals.push_back({info[i].dinner_start, info[i].dinner_end});
  }

  std::sort(intervals.begin(), intervals.end());
  
  int max_overlaps = 0;
  for (int i = 0; i < intervals.size(); i++) {
    int overlaps = 0;
    for (int j = i; j < intervals.size(); j++) {
      if (intervals[j].first <= intervals[i].second) {
        overlaps++;
      }
    }
    max_overlaps = std::max(max_overlaps, overlaps);
  }

  std::cout << max_overlaps << std::endl;
  
  return 0;
}