#include <cstdio>

int main() {
  int n;
  std::scanf("%d", &n);
  std::printf("%lld\n", static_cast<long long>(n) * n * n);
  return 0;
}