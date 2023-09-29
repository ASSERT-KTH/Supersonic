#include <algorithm>
#include <cstdio>
#include <cstring>
#define ll long long
#define maxn 100009
#define inf 999999999999
using namespace std;
ll dp1[10009];
ll dp2[10006];
char s[25];
int num[105];
int main() {
  int n, m, x, y;
  while (scanf("%d", &n) != EOF) {
    if (n == 0)
      break;
    for (int i = 0; i < n; i++)
      scanf("%d", &num[i]);
    sort(num, num + n);
    for (int i = 1; i <= 1000; i++)
      dp2[i] = -inf;
    dp2[0] = 0;
    memset(dp1, 0, sizeof dp1);
    scanf("%d", &m);
    bool flag = 0;
    for (int i = 0; i < m; i++) {
      scanf("%s", s);
      scanf("%d", &x);
      scanf("%s", s);
      scanf("%d", &y);
      if (x == 0 && y > 0)
        flag = 1;
      if (s[0] == 'S') {
        for (int j = x; j <= 10000; j++)
          dp1[j] = max(dp1[j], dp1[j - x] + y);
      } else {
        for (int j = x; j <= 10000; j++)
          dp2[j] = max(dp2[j], dp2[j - x] + y);
      }
