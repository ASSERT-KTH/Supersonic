#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Info {
  int start, end;
};

int calc(int hour, int minute) {
  return 60 * hour + minute;
}

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
    info[i].start = calc(m_st_h, m_st_m);
    info[i].end = calc(d_ed_h, d_ed_m);
    MORNING.push_back(info[i].start);
    MORNING.push_back(info[i].end);
    LUNCH.push_back(info[i].start);
    LUNCH.push_back(info[i].end);
    DINNER.push_back(info[i].start);
    DINNER.push_back(info[i].end);
  }
  
  sort(MORNING.begin(), MORNING.end());
  sort(LUNCH.begin(), LUNCH.end());
  sort(DINNER.begin(), DINNER.end());
  
  map<tuple<int, int, int>, int> countMap;
  
  for (int a = 0; a < MORNING.size(); a++) {
    for (int b = 0; b < LUNCH.size(); b++) {
      for (int c = 0; c < DINNER.size(); c++) {
        int count = 0;
        for (int i = 0; i < N; i++) {
          if (info[i].start <= MORNING[a] &&
              info[i].end >= DINNER[c]) {
            count++;
          }
        }
        countMap[make_tuple(MORNING[a], LUNCH[b], DINNER[c])] = count;
      }
    }
  }
  
  int ans = 0;
  
  for (auto it = countMap.begin(); it != countMap.end(); ++it) {
    ans = max(ans, it->second);
  }
  
  printf("%d\n", ans);
  
  return 0;
}