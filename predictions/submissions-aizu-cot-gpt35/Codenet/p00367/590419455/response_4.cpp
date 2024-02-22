#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int calc(int hour, int minute) {
  return 60 * hour + minute;
}

int main() {
  int N;
  cin >> N;

  int m_st_h, m_st_m, m_ed_h, m_ed_m, l_st_h, l_st_m, l_ed_h, l_ed_m, d_st_h, d_st_m, d_ed_h, d_ed_m;
  vector<int> morning_start, morning_end, lunch_start, lunch_end, dinner_start, dinner_end;

  for (int i = 0; i < N; i++) {
    cin >> m_st_h >> m_st_m >> m_ed_h >> m_ed_m >> l_st_h >> l_st_m >> l_ed_h >> l_ed_m >> d_st_h >> d_st_m >> d_ed_h >> d_ed_m;

    morning_start.push_back(calc(m_st_h, m_st_m));
    morning_end.push_back(calc(m_ed_h, m_ed_m));
    lunch_start.push_back(calc(l_st_h, l_st_m));
    lunch_end.push_back(calc(l_ed_h, l_ed_m));
    dinner_start.push_back(calc(d_st_h, d_st_m));
    dinner_end.push_back(calc(d_ed_h, d_ed_m));
  }

  sort(morning_start.begin(), morning_start.end());
  sort(morning_end.begin(), morning_end.end());
  sort(lunch_start.begin(), lunch_start.end());
  sort(lunch_end.begin(), lunch_end.end());
  sort(dinner_start.begin(), dinner_start.end());
  sort(dinner_end.begin(), dinner_end.end());

  int ans = 0;
  int tmp;
  for (int a = 0; a < morning_start.size(); a++) {
    for (int b = 0; b < lunch_start.size(); b++) {
      for (int c = 0; c < dinner_start.size(); c++) {
        tmp = 0;
        for (int i = 0; i < N; i++) {
          if (morning_start[i] <= morning_start[a] && morning_end[i] >= morning_start[a] &&
              lunch_start[i] <= lunch_start[b] && lunch_end[i] >= lunch_start[b] &&
              dinner_start[i] <= dinner_start[c] && dinner_end[i] >= dinner_start[c]) {
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