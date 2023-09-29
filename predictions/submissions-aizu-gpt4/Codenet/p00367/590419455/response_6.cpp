#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

struct Info {
  int mornint_start, morning_end, lunch_start, lunch_end, dinner_start, dinner_end;
};

int main() {
  int N;
  scanf("%d", &N);

  vector<Info> schedule(N);

  for (int i = 0; i < N; i++) {
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d", 
          &schedule[i].mornint_start, &schedule[i].morning_end,
          &schedule[i].lunch_start, &schedule[i].lunch_end,
          &schedule[i].dinner_start, &schedule[i].dinner_end);

    schedule[i].mornint_start *= 60;
    schedule[i].morning_end *= 60;
    schedule[i].lunch_start *= 60;
    schedule[i].lunch_end *= 60;
    schedule[i].dinner_start *= 60;
    schedule[i].dinner_end *= 60;
  }

  int ans = 0, tmp;
  for (int a = 0; a < N; a++) {
    for (int b = 0; b < N; b++) {
      for (int c = 0; c < N; c++) {
        tmp = 0;
        for (int i = 0; i < N; i++) {
          if (schedule[i].mornint_start <= schedule[a].mornint_start &&
              schedule[i].morning_end >= schedule[a].morning_end &&
              schedule[i].lunch_start <= schedule[b].lunch_start &&
              schedule[i].lunch_end >= schedule[b].lunch_end &&
              schedule[i].dinner_start <= schedule[c].dinner_start &&
              schedule[i].dinner_end >= schedule[c].dinner_end) {
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