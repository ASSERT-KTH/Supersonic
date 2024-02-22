#include <iostream>
#include <unordered_map>
#include <vector>

struct Info {
  int morning_start, morning_end, lunch_start, lunch_end, dinner_start,
      dinner_end;
};

int calc(int hour, int minute) {
  return 60 * hour + minute;
}

int main() {
  int N;
  std::cin >> N;

  std::vector<Info> info(N);
  std::vector<int> MORNING, LUNCH, DINNER;

  for (int i = 0; i < N; i++) {
    int m_st_h, m_st_m, m_ed_h, m_ed_m, l_st_h, l_st_m, l_ed_h, l_ed_m, d_st_h,
        d_st_m, d_ed_h, d_ed_m;
    std::cin >> m_st_h >> m_st_m >> m_ed_h >> m_ed_m >> l_st_h >> l_st_m >>
        l_ed_h >> l_ed_m >> d_st_h >> d_st_m >> d_ed_h >> d_ed_m;

    info[i].morning_start = calc(m_st_h, m_st_m);
    info[i].morning_end = calc(m_ed_h, m_ed_m);
    MORNING.push_back(info[i].morning_start);
    MORNING.push_back(info[i].morning_end);

    info[i].lunch_start = calc(l_st_h, l_st_m);
    info[i].lunch_end = calc(l_ed_h, l_ed_m);
    LUNCH.push_back(info[i].lunch_start);
    LUNCH.push_back(info[i].lunch_end);

    info[i].dinner_start = calc(d_st_h, d_st_m);
    info[i].dinner_end = calc(d_ed_h, d_ed_m);
    DINNER.push_back(info[i].dinner_start);
    DINNER.push_back(info[i].dinner_end);
  }

  int ans = 0;

  std::unordered_map<int, int> morning_count, lunch_count, dinner_count;

  for (int i = 0; i < N; i++) {
    morning_count[info[i].morning_start]++;
    morning_count[info[i].morning_end]++;

    lunch_count[info[i].lunch_start]++;
    lunch_count[info[i].lunch_end]++;

    dinner_count[info[i].dinner_start]++;
    dinner_count[info[i].dinner_end]++;
  }

  for (const auto& morning_time : morning_count) {
    for (const auto& lunch_time : lunch_count) {
      for (const auto& dinner_time : dinner_count) {
        int tmp = 0;
        for (int i = 0; i < N; i++) {
          if (info[i].morning_start <= morning_time.first &&
              info[i].morning_end >= morning_time.first &&
              info[i].lunch_start <= lunch_time.first &&
              info[i].lunch_end >= lunch_time.first &&
              info[i].dinner_start <= dinner_time.first &&
              info[i].dinner_end >= dinner_time.first) {
            tmp++;
          }
        }
        if (tmp > ans) {
          ans = tmp;
        }
      }
    }
  }

  std::cout << ans << std::endl;

  return 0;
}