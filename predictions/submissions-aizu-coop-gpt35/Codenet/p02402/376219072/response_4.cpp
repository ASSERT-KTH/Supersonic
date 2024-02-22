#include <cstdio>
#include <algorithm>
#include <numeric>
#include <vector>

int main() {
  int n;
  std::vector<int> a;
  scanf("%d", &n);
  a.reserve(n);
  for (int i = 0; i < n; i++) {
    int ii;
    scanf("%d", &ii);
    a.push_back(ii);
  }
  
  int min = *std::min_element(a.begin(), a.end());
  int max = *std::max_element(a.begin(), a.end());
  long long sum = std::accumulate(a.begin(), a.end(), 0LL);
  
  printf("%d %d %lld\n", min, max, sum);
}