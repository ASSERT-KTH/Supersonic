#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int main() {
  int n, k;
  while (scanf("%d %d", &n, &k), n) {
    vector<long long> ac(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &ac[i]);
      ac[i] += ac[i - 1];
    }
    long long res = -LLONG_MAX;
    for (int i = k; i <= n; ++i) {
      res = max(res, ac[i] - ac[i - k]);
    }
    printf("%lld\n", res);
  }
  return 0;
}