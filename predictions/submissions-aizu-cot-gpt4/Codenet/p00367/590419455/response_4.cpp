#include <algorithm>
#include <stdio.h>
#include <vector>
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;
struct Info {
  int mornint_start, morning_end, lunch_start, lunch_end, dinner_start,
      dinner_end;
};
int calc(int hour, int minute) { return 60 * hour + minute; }
int main() {
  int N;
  scanf("%d", &N);
  Info info[N];
  vector<int> MORNING, LUNCH, DINNER;

  for (int i = 0; i < N; i++) {
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &info[i].mornint_start, 
    &info[i].morning_end, &info[i].lunch_start, &info[i].lunch_end, 
    &info[i].dinner_start, &info[i].dinner_end);
    
    info[i].mornint_start = calc(info[i].mornint_start, info[i].morning_end);
    info[i].morning_end = calc(info[i].mornint_start, info[i].morning_end);
    MORNING.push_back(info[i].mornint_start);
    MORNING.push_back(info[i].morning_end);
    
    info[i].lunch_start = calc(info[i].lunch_start, info[i].lunch_end);
    info[i].lunch_end = calc(info[i].lunch_start, info[i].lunch_end);
    LUNCH.push_back(info[i].lunch_start);
    LUNCH.push_back(info[i].lunch_end);
    
    info[i].dinner_start = calc(info[i].dinner_start, info[i].dinner_end);
    info[i].dinner_end = calc(info[i].dinner_start, info[i].dinner_end);
    DINNER.push_back(info[i].dinner_start);
    DINNER.push_back(info[i].dinner_end);
  }

  sort(MORNING.begin(), MORNING.end());
  sort(LUNCH.begin(), LUNCH.end());
  sort(DINNER.begin(), DINNER.end());

  int ans = 0, tmp;

  for (int a = 0; a < MORNING.size(); a++) {
    for (int b = 0; b < LUNCH.size(); b++) {
      for (int c = 0; c < DINNER.size(); c++) {
        tmp = 0;
        for (int i = 0; i < N; i++) {
          if (info[i].mornint_start <= MORNING[a] &&
              info[i].morning_end >= MORNING[a] &&
              info[i].lunch_start <= LUNCH[b] &&
              info[i].lunch_end >= LUNCH[b] &&
              info[i].dinner_start <= DINNER[c] &&
              info[i].dinner_end >= DINNER[c]) {
            tmp++;
          }
        }
        if (tmp > ans) {
          ans = tmp;
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}