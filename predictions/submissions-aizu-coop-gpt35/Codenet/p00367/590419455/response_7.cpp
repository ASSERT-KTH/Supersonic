#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct Info {
  int morning_start, morning_end, lunch_start, lunch_end, dinner_start, dinner_end;
};

int calc(int hour, int minute) {
  return 60 * hour + minute;
}

int main() {
  int N;
  cin >> N;
  
  vector<Info> info(N);
  multiset<int> morning, lunch, dinner;

  for (int i = 0; i < N; i++) {
    int m_st_h, m_st_m, m_ed_h, m_ed_m, l_st_h, l_st_m, l_ed_h, l_ed_m, d_st_h, d_st_m, d_ed_h, d_ed_m;
    cin >> m_st_h >> m_st_m >> m_ed_h >> m_ed_m >> l_st_h >> l_st_m >> l_ed_h >> l_ed_m >> d_st_h >> d_st_m >> d_ed_h >> d_ed_m;

    info[i].morning_start = calc(m_st_h, m_st_m);
    info[i].morning_end = calc(m_ed_h, m_ed_m);
    morning.insert(info[i].morning_start);
    morning.insert(info[i].morning_end);

    info[i].lunch_start = calc(l_st_h, l_st_m);
    info[i].lunch_end = calc(l_ed_h, l_ed_m);
    lunch.insert(info[i].lunch_start);
    lunch.insert(info[i].lunch_end);

    info[i].dinner_start = calc(d_st_h, d_st_m);
    info[i].dinner_end = calc(d_ed_h, d_ed_m);
    dinner.insert(info[i].dinner_start);
    dinner.insert(info[i].dinner_end);
  }

  int ans = 0;

  for (int morning_time : morning) {
    for (int lunch_time : lunch) {
      for (int dinner_time : dinner) {
        int tmp = 0;
        for (const Info& person : info) {
          if (person.morning_start <= morning_time && person.morning_end >= morning_time &&
              person.lunch_start <= lunch_time && person.lunch_end >= lunch_time &&
              person.dinner_start <= dinner_time && person.dinner_end >= dinner_time) {
            tmp++;
          }
        }
        if (tmp > ans) {
          ans = tmp;
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}