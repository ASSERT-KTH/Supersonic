
#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <map>
#include <vector>

using int32 = std::int_fast32_t;
using int64 = std::int_fast64_t;
using uint32 = std::uint_fast32_t;
using uint64 = std::uint_fast64_t;

// ... Rest of the code is same ...

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  uint32 n, q;
  std::cin >> n >> q;

  std::vector<douse> a(n);
  a.reserve(n);

  int32 t1;
  for (uint32 i = 0; i < n; ++i) {
    std::cin >> t1;
    a[i] = douse(t1, t1, t1, t1, 1);
  }

  // ... Rest of the code is same ...

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
