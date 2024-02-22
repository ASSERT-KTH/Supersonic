#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <vector>

using int32 = std::int_fast32_t;
using int64 = std::int_fast64_t;
using uint32 = std::uint_fast32_t;
using uint64 = std::uint_fast64_t;
using intl32 = std::int_least32_t;
using intl64 = std::int_least64_t;
using uintl32 = std::uint_least32_t;
using uintl64 = std::uint_least64_t;

// ... Rest of the code unchanged ...

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  uint32 n, q;
  std::cin >> n >> q;
  std::vector<douse> a(n);
  int32 t1;
  for (uint32 i = 0; i < n; ++i) {
    std::cin >> t1;
    a[i] = douse(t1, t1, t1, t1, 1);
  }
  link_cut_tree<douse, ass> L(a);
  uint32 t2, t3;
  for (uint32 i = 0; i < n - 1; ++i) {
    std::cin >> t2 >> t3;
    L.link(t2 - 1, t3 - 1);
  }
  uint32 t4;
  for (uint32 i = 0; i < q; ++i) {
    std::cin >> t2 >> t3 >> t4 >> t1;
    if (t2 == 1) {
      L.update(t3 - 1, t4 - 1, ass(t1));
    } else {
      std::cout << L.path(t3 - 1, t4 - 1).all << "\n";
    }
  }
  return 0;
}