#include <iostream>
#include <vector>

using int32 = std::int_fast32_t;
using uint32 = std::uint_fast32_t;
using intl32 = std::int_least32_t;

// Removed unused headers and typedefs

// Rest of the code remains the same

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  uint32 totalNodes, totalQueries;
  std::cin >> totalNodes >> totalQueries;
  std::vector<douse> arr(totalNodes);
  int32 temp1;
  for (uint32 i = 0; i < totalNodes; ++i) {
    std::cin >> temp1;
    arr[i] = douse(temp1, temp1, temp1, temp1, 1);
  }
  link_cut_tree<douse, ass> L(arr);
  uint32 temp2, temp3;
  for (uint32 i = 0; i < totalNodes - 1; ++i) {
    std::cin >> temp2 >> temp3;
    L.link(temp2 - 1, temp3 - 1);
    L.scan();
  }
  uint32 temp4;
  for (uint32 i = 0; i < totalQueries; ++i) {
    L.scan();
    std::cin >> temp2 >> temp3 >> temp4 >> temp1;
    if (temp2 == 1) {
      L.update(temp3 - 1, temp4 - 1, ass(temp1));
    } else {
      std::cout << L.path(temp3 - 1, temp4 - 1).all << "\n";
    }
  }
  return 0;
}