#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Info {
public:
  int morning_start, morning_end, lunch_start, lunch_end, dinner_start,
      dinner_end;

  static int calc(int hour, int minute) { return 60 * hour + minute; }
};

int main() {
  int N;
  cin >> N;
  vector<Info> info(N);

  unordered_map<int, int> morning_counts, lunch_counts, dinner_counts;

  for (int i = 0; i < N; i++) {
    int m_st_h, m_st_m, m_ed_h, m_ed_m, l_st_h, l_st_m, l_ed_h, l_ed_m,
        d_st_h, d_st_m, d_ed_h, d_ed_m;
    cin >> m_st_h >> m_st_m >> m_ed_h >> m_ed_m >> l_st_h >> l_st_m >> l_ed_h >>
        l_ed_m >> d_st_h >> d_st_m >> d_ed_h >> d_ed_m;

    info[i].morning_start = Info::calc(m_st_h, m_st_m);
    info[i].morning_end = Info::calc(m_ed_h, m_ed_m);

    info[i].lunch_start = Info::calc(l_st_h, l_st_m);
    info[i].lunch_end = Info::calc(l_ed_h, l_ed_m);

    info[i].dinner_start = Info::calc(d_st_h, d_st_m);
    info[i].dinner_end = Info::calc(d_ed_h, d_ed_m);

    morning_counts[info[i].morning_start]++;
    morning_counts[info[i].morning_end + 1]--;

    lunch_counts[info[i].lunch_start]++;
    lunch_counts[info[i].lunch_end + 1]--;

    dinner_counts[info[i].dinner_start]++;
    dinner_counts[info[i].dinner_end + 1]--;
  }

  int ans = 0, tmp = 0;
  for (auto& kv : morning_counts) {
    tmp += kv.second;
    kv.second = tmp;
  }

  tmp = 0;
  for (auto& kv : lunch_counts) {
    tmp += kv.second;
    kv.second = tmp;
  }

  tmp = 0;
  for (auto& kv : dinner_counts) {
    tmp += kv.second;
    kv.second = tmp;
  }

  for (auto& kv_m : morning_counts) {
    for (auto& kv_l : lunch_counts) {
      for (auto& kv_d : dinner_counts) {
        int count = 0;
        for (int i = 0; i < N; i++) {
          if (info[i].morning_start <= kv_m.first && info[i].morning_end >= kv_m.first &&
              info[i].lunch_start <= kv_l.first && info[i].lunch_end >= kv_l.first &&
              info[i].dinner_start <= kv_d.first && info[i].dinner_end >= kv_d.first) {
            count++;
          }
        }
        ans = max(ans, count);
      }
    }
  }

  cout << ans << endl;
  return 0;
}