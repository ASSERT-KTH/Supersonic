#include <algorithm>
#include <cstdio>
#include <cstring>
#define ll long long
#define maxn 100009
#define inf 999999999999
using namespace std;

ll dp1[10001]; // Reduce the size of dp1 array
ll dp2[10001]; // Reduce the size of dp2 array
char s[25];
int num[105];

int binary_search(int arr[], int n, int target) {
  int low = 0;
  int high = n - 1;
  int result = -1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) {
      result = mid;
      high = mid - 1; // Continue searching for a lower index
    } else if (arr[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return result;
}

int main() {
  int n, m, x, y;
  while (scanf("%d", &n) != EOF) {
    if (n == 0)
      break;
    for (int i = 0; i < n; i++)
      scanf("%d", &num[i]);

    int min_num = *min_element(num, num + n); // Efficiently find the minimum value in num array

    for (int i = 1; i <= min(10000, min_num - 1); i++) // Initialize dp2 only until min_num - 1
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
        for (int j = x; j <= min(10000, min_num + 10000 - 1); j++) // Optimize loop by iterating only until min_num + 10000 - 1
          dp1[j] = max(dp1[j], dp1[j - x] + y);
      } else {
        for (int j = x; j <= min(10000, min_num + 10000 - 1); j++) // Optimize loop by iterating only until min_num + 10000 - 1
          dp2[j] = max(dp2[j], dp2[j - x] + y);
      }
    }
    if (flag) {
      puts("0");
      continue;
    }
    ll ans = 1ll << 60, sum;
    for (int i = 0; i < min(10001, min_num + 10000); i++) { // Optimize loop by iterating only until min_num + 10000
      if (dp2[i] < 0)
        continue;
      sum = i;
      for (int j = 0; j < n; j++) {
        int index = binary_search(dp1, min_num + 10000, num[j] - dp2[i]); // Use binary search to find the index
        if (index != -1)
          sum += index;
      }
      ans = min(ans, sum);
    }
    printf("%lld\n", ans);
  }
  return 0;
}