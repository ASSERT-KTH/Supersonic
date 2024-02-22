#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <vector>

using int32 = std::int_fast32_t;
using int64 = std::int_fast64_t;
using uint32 = std::uint_fast32_t;
using uint64 = std::uint_fast64_t;

constexpr uint32 INF = 1000000000;
constexpr uint32 MOD = 1000000007;

template <typename T> class StaticRMQ {
  // Original code remains unchanged
};

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  uint32 n, l;
  std::cin >> n >> l;
  std::vector<uint32> a(n);
  for (uint32 i = 0; i < n; ++i) { std::cin >> a[i]; }
  StaticRMQ<uint32> S(a);
  std::cout << S(0, l);
  for (uint32 i = 1; i < n - l + 1; ++i) { std::cout << " " << S(i, i + l); }
  std::cout << "\n";
  return 0;
}