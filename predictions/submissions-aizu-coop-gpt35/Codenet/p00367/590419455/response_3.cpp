#include <algorithm>
#include <iostream>
#include <vector>

struct Info {
  int morning_start, morning_end, lunch_start, lunch_end, dinner_start,
      dinner_end;
};

int calc(int hour, int minute) {
  return 60 * hour + minute;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int N;
  std::cin >> N;

  std::vector<Info> info(N);
  std::vector<int> morning_start, morning_end, lunch_start, lunch_end,
      dinner_start, dinner_end;

  for (int i = 0; i < N; i++) {
    int m_st_h, m_st_m, m_ed_h, m_ed_m, l_st_h, l_st_m, l_ed_h, l_ed_m, d_st_h,
        d_st_m, d_ed_h, d_ed_m;
    std::cin >> m_st_h >> m_st_m >> m_ed_h >> m_ed_m >> l_st_h >> l_st_m >>
        l_ed_h >> l_ed_m >> d_st_h >> d_st_m >> d_ed_h >> d_ed_m;

    info[i].morning_start = calc(m_st_h, m_st_m);
    info[i].morning_end = calc(m_ed_h, m_ed_m);
    info[i].lunch_start = calc(l_st_h, l_st_m);
    info[i].lunch_end = calc(l_ed_h, l_ed_m);
    info[i].dinner_start = calc(d_st_h, d_st_m);
    info[i].dinner_end = calc(d_ed_h, d_ed_m);

    morning_start.push_back(info[i].morning_start);
    morning_end.push_back(info[i].morning_end);
    lunch_start.push_back(info[i].lunch_start);
    lunch_end.push_back(info[i].lunch_end);
    dinner_start.push_back(info[i].dinner_start);
    dinner_end.push_back(info[i].dinner_end);
  }

  std::sort(morning_start.begin(), morning_start.end());
  std::sort(morning_end.begin(), morning_end.end());
  std::sort(lunch_start.begin(), lunch_start.end());
  std::sort(lunch_end.begin(), lunch_end.end());
  std::sort(dinner_start.begin(), dinner_start.end());
  std::sort(dinner_end.begin(), dinner_end.end());

  int ans = 0;

  for (int a = 0; a < morning_start.size(); a++) {
    for (int b = 0; b < lunch_start.size(); b++) {
      for (int c = 0; c < dinner_start.size(); c++) {
        int tmp = 0;
        for (int i = 0; i < N; i++) {
          if (info[i].morning_start <= morning_start[a] &&
              info[i].morning_end >= morning_end[a] &&
              info[i].lunch_start <= lunch_start[b] &&
              info[i].lunch_end >= lunch_end[b] &&
              info[i].dinner_start <= dinner_start[c] &&
              info[i].dinner_end >= dinner_end[c]) {
            tmp++;
          }
        }
        ans = std::max(ans, tmp);
      }
    }
  }

  std::cout << ans << std::endl;

  return 0;
}