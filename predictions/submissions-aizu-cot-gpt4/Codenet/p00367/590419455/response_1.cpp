#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;
struct Info {
  int mornint_start, morning_end, lunch_start, lunch_end, dinner_start,
      dinner_end;
};
struct Interval {
  int start, end;
  bool operator<(const Interval &other) const { return end > other.end; }
};
int calc(int hour, int minute) { return 60 * hour + minute; }
int main() {
  int N;
  scanf("%d", &N);
  Info info[N];
  vector<Interval> MORNING(N), LUNCH(N), DINNER(N);
  for (int i = 0; i < N; i++) {
    int m_st_h, m_st_m, m_ed_h, m_ed_m, l_st_h, l_st_m, l_ed_h, l_ed_m, d_st_h,
        d_st_m, d_ed_h, d_ed_m;
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &m_st_h, &m_st_m, &m_ed_h,
          &m_ed_m, &l_st_h, &l_st_m, &l_ed_h, &l_ed_m, &d_st_h, &d_st_m,
          &d_ed_h, &d_ed_m);
    info[i].mornint_start = calc(m_st_h, m_st_m);
    info[i].morning_end = calc(m_ed_h, m_ed_m);
    MORNING[i] = {info[i].mornint_start, info[i].morning_end};
    info[i].lunch_start = calc(l_st_h, l_st_m);
    info[i].lunch_end = calc(l_ed_h, l_ed_m);
    LUNCH[i] = {info[i].lunch_start, info[i].lunch_end};
    info[i].dinner_start = calc(d_st_h, d_st_m);
    info[i].dinner_end = calc(d_ed_h, d_ed_m);
    DINNER[i] = {info[i].dinner_start, info[i].dinner_end};
  }
  sort(MORNING.begin(), MORNING.end());
  sort(LUNCH.begin(), LUNCH.end());
  sort(DINNER.begin(), DINNER.end());
  int ans = 0;
  priority_queue<Interval> pq;
  for (int i = 0; i < N; i++) {
    while (!pq.empty() && pq.top().end < MORNING[i].start) {
      pq.pop();
    }
    pq.push(MORNING[i]);
    ans = max(ans, (int)pq.size());
  }
  printf("%d\n", ans);
  return 0;
}