#include <algorithm>
#include <array>
#include <cstdint>
#include <vector>
using int32 = std::int_fast32_t;
using int64 = std::int_fast64_t;
using uint32 = std::uint_fast32_t;
using uint64 = std::uint_fast64_t;
#define rep(i, a, b) for (uint32 i = (a); i < (b); ++i)
#define ALL(x) (x).begin(), (x).end()
using namespace std;

// Remainder of your StaticRMQ class goes here...

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  uint32 n, l;
  std::cin >> n >> l;
  std::vector<uint32> a(n);
  rep(i, 0, n) { std::cin >> a[i]; }
  StaticRMQ<uint32> S(a);
  std::cout << S(0, l);
  rep(i, 1, n - l + 1) { std::cout << " " << S(i, i + l); }
  std::cout << "\n";
  return 0;
}