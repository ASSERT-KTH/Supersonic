#include <set>
#include <stdio.h>

struct Info {
  int morning_start, morning_end, lunch_start, lunch_end, dinner_start, dinner_end;
};

int calc(int hour, int minute) {
  return 60 * hour + minute;
}

int main() {
  int N;
  scanf("%d", &N);
  Info info[N];
  std::multiset<std::pair<int, bool>> times;
  for (int i = 0; i < N; i++) {
    int m_st_h, m_st_m, m_ed_h, m_ed_m, l_st_h, l_st_m, l_ed_h, l_ed_m, d_st_h, d_st_m, d_ed_h, d_ed_m;
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &m_st_h, &m_st_m, &m_ed_h, &m_ed_m, &l_st_h, &l_st_m, &l_ed_h, &l_ed_m, &d_st_h, &d_st_m, &d_ed_h, &d_ed_m);
    info[i].morning_start = calc(m_st_h, m_st_m);
    info[i].morning_end = calc(m_ed_h, m_ed_m);
    info[i].lunch_start = calc(l_st_h, l_st_m);
    info[i].lunch_end = calc(l_ed_h, l_ed_m);
    info[i].dinner_start = calc(d_st_h, d_st_m);
    info[i].dinner_end = calc(d_ed_h, d_ed_m);
    times.insert({info[i].morning_start, true});
    times.insert({info[i].morning_end, false});
    times.insert({info[i].lunch_start, true});
    times.insert({info[i].lunch_end, false});
    times.insert({info[i].dinner_start, true});
    times.insert({info[i].dinner_end, false});
  }
  int max_people = 0, people = 0;
  for (const auto &time : times) {
    if (time.second) { // start time
      people++;
    } else { // end time
      people--;
    }
    if (people > max_people) {
      max_people = people;
    }
  }
  printf("%d\n", max_people);
  return 0;
}