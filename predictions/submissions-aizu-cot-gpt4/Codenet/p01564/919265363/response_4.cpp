#include <iostream>
#include <vector>

using int32 = std::int_fast32_t;
using uint32 = std::uint_fast32_t;

template <typename Monoid, typename Operand> class link_cut_tree {
  // ... keeping the class definition as it is ...
};

struct ass {
  int32 data;
  ass(int32 a = 0) : data(a) {}
  ass operator*(const ass &other) { return other; }
};

struct douse {
  // ... keeping the structure definition as it is ...
};

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  uint32 n, q;
  std::cin >> n >> q;
  std::vector<douse> a(n);
  int32 temp;
  for (uint32 i = 0; i < n; ++i) {
    std::cin >> temp;
    a[i] = douse(temp, temp, temp, temp, 1);
  }
  link_cut_tree<douse, ass> L(a);
  uint32 t2, t3, t4;
  for (uint32 i = 0; i < n - 1; ++i) {
    std::cin >> t2 >> t3;
    L.link(t2 - 1, t3 - 1);
  }
  for (uint32 i = 0; i < q; ++i) {
    std::cin >> t2 >> t3 >> t4 >> temp;
    if (t2 == 1) {
      L.update(t3 - 1, t4 - 1, ass(temp));
    } else {
      std::cout << L.path(t3 - 1, t4 - 1).all << "\n";
    }
  }
  return 0;
}