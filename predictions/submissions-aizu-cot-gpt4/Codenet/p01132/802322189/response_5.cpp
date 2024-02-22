#include <cstdio>
#define MAX 4
#define INF 1e+9
#define pii pair<int,int>
#define mp make_pair

int payment(int *p) {
  return 10 * p[0] + 50 * p[1] + 100 * p[2] + 500 * p[3];
}

void charge(int m, int *ans) {
  ans[3] = m / 500;
  m -= ans[3] * 500;
  ans[2] = m / 100;
  m -= ans[2] * 100;
  ans[1] = m / 50;
  m -= ans[1] * 50;
  ans[0] = m / 10;
}

bool judge(int *f, int *ch) {
  for (int i = 0; i < MAX; ++i)
    if (f[i] == 1 && ch[i] > 0)
      return false;
  return true;
}

int main() {
  int N;
  scanf("%d", &N);
  while (1) {
    int c[MAX], sum = 0, f[MAX] = {0, 0, 0, 0}, mini = INF, pay[MAX], ans[MAX];
    for (int i = 0; i < MAX; ++i) {
      scanf("%d", &c[i]);
      sum += c[i];
    }
    for (pay[0] = 0; pay[0] <= c[0]; ++pay[0]) {
      if (pay[0] > 0)
        f[0] = 1;
      for (pay[1] = 0; pay[1] <= c[1]; ++pay[1]) {
        if (pay[1] > 0)
          f[1] = 1;
        for (pay[2] = 0; pay[2] <= c[2]; ++pay[2]) {
          if (pay[2] > 0)
            f[2] = 1;
          for (pay[3] = 0; pay[3] <= c[3]; ++pay[3]) {
            if (pay[3] > 0)
              f[3] = 1;
            int m_pay = payment(pay);
            if (m_pay >= N) {
              int ch[MAX];
              charge(m_pay - N, ch);
              if (mini > sum - pay[0] - pay[1] - pay[2] - pay[3] + ch[0] + ch[1] + ch[2] + ch[3]) {
                if (judge(f, ch)) {
                  for (int i = 0; i < MAX; ++i)
                    ans[i] = pay[i];
                  mini = sum - pay[0] - pay[1] - pay[2] - pay[3] + ch[0] + ch[1] + ch[2] + ch[3];
                }
              }
            }
            f[3] = 0;
          }
          f[2] = 0;
        }
        f[1] = 0;
      }
      f[0] = 0;
    }
    int deno[] = {10, 50, 100, 500};
    for (int i = 0; i < MAX; ++i) {
      if (ans[i] > 0)
        printf("%d %d\n", deno[i], ans[i]);
    }
    scanf("%d", &N);
    if (!N)
      break;
    printf("\n");
  }
}