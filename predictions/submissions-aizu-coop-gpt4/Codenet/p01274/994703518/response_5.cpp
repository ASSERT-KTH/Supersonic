#include <algorithm>
#include <cstdio>
#define ll long long
#define maxn 100009
#define inf 999999999999

enum COMMAND {UNKNOWN, COMMAND_S, COMMAND_OTHER};
ll dp1[10009] = {0}; //Initialized to 0
ll dp2[10006];
int num[105];

// Function to perform binary search
int binary_search(ll arr[], int l, int r, ll x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binary_search(arr, l, mid - 1, x);
        return binary_search(arr, mid + 1, r, x);
    }
    return -1;
}

int main() {
  int n, m, x, y;
  while (scanf("%d", &n) != EOF) {
    if (n == 0)
      break;
    for (int i = 0; i < n; i++)
      scanf("%d", &num[i]);
    sort(num, num + n);
    for (int i = 1; i <= 10000; i++)
      dp2[i] = -inf;
    scanf("%d", &m);
    bool flag = 0;
    for (int i = 0; i < m; i++) {
      COMMAND command = UNKNOWN;
      scanf("%d", &command);
      scanf("%d", &x);
      scanf("%d", &y);
      if (x == 0 && y > 0)
        flag = 1;
      if (command == COMMAND_S) {
        for (int j = x; j <= 10000; j++)
          dp1[j] = max(dp1[j], dp1[j - x] + y);
      } else {
        for (int j = x; j <= 10000; j++)
          dp2[j] = max(dp2[j], dp2[j - x] + y);
      }
    }
    if (flag) {
      puts("0");
      continue;
    }
    ll ans = 1ll << 60, sum;
    for (int i = 0; i < 10001; i++) {
      if (dp2[i] < 0)
        continue;
      sum = i;
      for (int j = 0; j < n; j++) {
        int index = binary_search(dp1, 0, 10000, num[j] - dp2[i]);
        if (index != -1)
            sum += index;
      }
      ans = min(ans, sum);
    }
    printf("%lld\n", ans);
  }
  return 0;
}