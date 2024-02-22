#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
int n, sumf, sums, dp[3000];
P book[1001];

int solve() {
  sumf = 2 * book[0].first - sumf;
  dp[0] = 1;
  for (int i = 1; i < n; i++)
    for (int j = sumf - book[i].second; j >= 0; j--)
      if(dp[j]) {
        dp[j + book[i].second] = 1;
        if(j + book[i].second == sumf) 
          return sums + sumf;
      }
  while (!dp[sumf])
    sumf--;
  return sums + sumf;
}

int main() {
  while (scanf("%d", &n), n) {
    sumf = sums = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &book[i].first, &book[i].second);
      sumf += book[i].first;
      sums += book[i].second;
    }
    sort(book, book + n, greater<P>());
    printf("%d\n", solve());
  }
  return 0;
}