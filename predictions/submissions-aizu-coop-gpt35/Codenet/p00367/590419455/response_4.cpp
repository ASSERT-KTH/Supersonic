#include <algorithm>
#include <iostream>
#include <array>
#include <stdio.h>
#include <vector>

typedef long long int ll;
typedef unsigned long long int ull;

#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001

int calc(int hour, int minute) {
  return 60 * hour + minute;
}

int main() {
  int N;
  scanf("%d", &N);

  std::array<std::array<int, 6>, N> info;
  std::array<int, N*2> MORNING, LUNCH, DINNER;

  for (int i = 0; i < N; i++) {
    int m_st_h, m_st_m, m_ed_h, m_ed_m, l_st_h, l_st_m, l_ed_h, l_ed_m, d_st_h, d_st_m, d_ed_h, d_ed_m;
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &m_st_h, &m_st_m, &m_ed_h, &m_ed_m, &l_st_h, &l_st_m, &l_ed_h, &l_ed_m, &d_st_h, &d_st_m, &d_ed_h, &d_ed_m);

    info[i][0] = calc(m_st_h, m_st_m);
    info[i][1] = calc(m_ed_h, m_ed_m);
    MORNING[i*2] = info[i][0];
    MORNING[i*2 + 1] = info[i][1];

    info[i][2] = calc(l_st_h, l_st_m);
    info[i][3] = calc(l_ed_h, l_ed_m);
    LUNCH[i*2] = info[i][2];
    LUNCH[i*2 + 1] = info[i][3];

    info[i][4] = calc(d_st_h, d_st_m);
    info[i][5] = calc(d_ed_h, d_ed_m);
    DINNER[i*2] = info[i][4];
    DINNER[i*2 + 1] = info[i][5];
  }

  std::sort(MORNING.begin(), MORNING.end());
  std::sort(LUNCH.begin(), LUNCH.end());
  std::sort(DINNER.begin(), DINNER.end());

  std::sort(info.begin(), info.end(), [](const std::array<int, 6>& a, const std::array<int, 6>& b) {
    return a[0] < b[0];
  });

  int ans = 0;
  int tmp;

  for (int a = 0; a < MORNING.size(); a++) {
    for (int b = 0; b < LUNCH.size(); b++) {
      for (int c = 0; c < DINNER.size(); c++) {
        tmp = 0;

        for (int i = 0; i < N; i++) {
          if (info[i][0] <= MORNING[a] &&
              info[i][1] >= MORNING[a] &&
              info[i][2] <= LUNCH[b] &&
              info[i][3] >= LUNCH[b] &&
              info[i][4] <= DINNER[c] &&
              info[i][5] >= DINNER[c]) {
            tmp++;
          }
          else if (info[i][0] > MORNING[a]) {
            // No need to continue checking as info array is sorted based on start times
            break;
          }
        }

        ans = std::max(ans, tmp);
      }
    }
  }

  printf("%d\n", ans);
  return 0;
}