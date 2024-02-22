#include <cstdio>
#include <cstring>

int n;
int t[10002];
int tmp[5002][2];

int minCost(const int &a, const int &b) {
  return a > b ? b : a;
}

int solve() {
  memset(tmp, -1, sizeof(tmp));
  tmp[1][0] = tmp[0][1] = 0;

  for (int i = 1; i < n; i++) {
    memset(tmp, -1, sizeof(tmp));
    for (int j = 0; j <= n / 2; j++) {
      for (int pre = 0; pre < 2; pre++) {
        if (tmp[j][pre] == -1)
          continue;
        for (int next = 0; next < 2; next++) {
          if (pre == next) {
            if (next == 0)
              tmp[j + 1][next] = minCost(tmp[j + 1][next], tmp[j][pre]);
            else
              tmp[j][next] = minCost(tmp[j][next], tmp[j][pre]);
          } else {
            if (next == 0)
              tmp[j + 1][next] =
                  minCost(tmp[j + 1][next], tmp[j][pre] + t[i - 1]);
            else
              tmp[j][next] = minCost(tmp[j][next], tmp[j][pre] + t[i - 1]);
          }
        }
      }
    }
  }

  return minCost(tmp[n / 2][0], tmp[n / 2][1]);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &t[i]);
  }
  printf("%d\n", solve());
}