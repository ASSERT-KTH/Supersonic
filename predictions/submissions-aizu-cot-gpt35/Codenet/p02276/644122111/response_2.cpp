#include <iostream>
#include <vector>

using uint = unsigned int;

static void print_partition_ints(const std::vector<int>& as, const uint q, const uint n) {
  auto out_sep = "";
  for (auto it = as.begin(); it != as.end(); ++it) {
    auto format = (std::distance(as.begin(), it) != q ? "%s%d" : "%s[%d]");
    std::cout << out_sep << *it;
    out_sep = " ";
  }
  std::cout << std::endl;
}

static uint partition(std::vector<int>& as, const uint first, const uint last) {
  auto pivot = as[last];
  auto less = first;
  
  auto it = as.begin() + first;
  auto end = as.begin() + last;
  std::partition(it, end, [pivot](int val) { return val <= pivot; });
  
  std::swap(as[less], as[last]);
  
  return less;
}

int main() {
  uint n;
  std::cin >> n;
  std::vector<int> as(n);
  
  for (auto i = 0u; i < n; ++i) {
    std::cin >> as[i];
  }
  
  auto q = partition(as, 0, n - 1);
  print_partition_ints(as, q, n);

  return 0;
}