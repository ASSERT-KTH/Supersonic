#include <iostream>
#include <vector>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<long long> a(n);
  long long min_val = 1e18; // Initialize with a large value
  long long max_val = -1e18; // Initialize with a small value
  long long sum = 0;

  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    min_val = std::min(min_val, a[i]);
    max_val = std::max(max_val, a[i]);
    sum += a[i];
  }
  
  printf("%lld %lld %lld\n", min_val, max_val, sum);

  return 0;
}