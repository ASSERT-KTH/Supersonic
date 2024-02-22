#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Info {
  int morning_start, morning_end, lunch_start, lunch_end, dinner_start, dinner_end;
};

int calc(int hour, int minute) { return 60 * hour + minute; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  vector<Info> info(N);
  for (int i = 0; i < N; i++) {
    int m_st_h, m_st_m, m_ed_h, m_ed_m, l_st_h, l_st_m, l_ed_h, l_ed_m, d_st_h, d_st_m, d_ed_h, d_ed_m;
    cin >> m_st_h >> m_st_m >> m_ed_h >> m_ed_m >> l_st_h >> l_st_m >> l_ed_h >> l_ed_m >> d_st_h >> d_st_m >> d_ed_h >> d_ed_m;

    info[i].morning_start = calc(m_st_h, m_st_m);
    info[i].morning_end = calc(m_ed_h, m_ed_m);
    info[i].lunch_start = calc(l_st_h, l_st_m);
    info[i].lunch_end = calc(l_ed_h, l_ed_m);
    info[i].dinner_start = calc(d_st_h, d_st_m);
    info[i].dinner_end = calc(d_ed_h, d_ed_m);
  }

  // Sort the info vector based on the end times of the meals
  sort(info.begin(), info.end(), [](const Info &a, const Info &b) {
    return tie(a.morning_end, a.lunch_end, a.dinner_end) <
           tie(b.morning_end, b.lunch_end, b.dinner_end);
  });

  int ans = 0;
  for (int i = 0; i < N; i++) {
    int tmp = 0;
    for (int j = i; j < N; j++) {
      if (info[j].morning_start >= info[i].morning_end &&
          info[j].lunch_start >= info[i].lunch_end &&
          info[j].dinner_start >= info[i].dinner_end) {
        tmp++;
        i = j;
      }
    }
    ans = max(ans, tmp);
  }

  cout << ans << "\n";
  return 0;
}