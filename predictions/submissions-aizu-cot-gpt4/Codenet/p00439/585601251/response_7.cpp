#include <algorithm>
#include <climits>
#include <cstdio>
using namespace std;
int main() {
  int n, k;
  while (scanf("%d%d", &n, &k), n) {
    long long sum = 0, res = -LLONG_MAX, num;
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &num);
      if(i <= k){
        sum += num;
      } else{
        sum = sum + num - ac[i - k];
      }
      if(i >= k){
        res = max(res, sum);
      } 
    }
    printf("%lld\n", res);
  }
  return 0;
}