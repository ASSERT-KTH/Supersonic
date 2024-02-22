#include <algorithm>
#include <iostream>
#include <vector>

void print_partition_ints(const std::vector<int>& as, const unsigned int q) {
  std::string out_sep = "";
  for (unsigned int i = 0; i < as.size(); ++i) {
    auto format = (i != q ? "%s%d" : "%s[%d]");
    std::cout << out_sep << (i != q ? as[i] : "[" + std::to_string(as[i]) + "]");
    out_sep = " ";
  }
  std::cout << std::endl;
}

unsigned int partition(std::vector<int>& as, const unsigned int first, const unsigned int last) {
  auto less = first;
  for (auto i = first; i < last; ++i) {
    if (as[i] <= as[last]) {
      std::swap(as[less], as[i]);
      ++less;
    }
  }
  std::swap(as[less], as[last]);
  return less;
}

int main() {
  unsigned int n;
  std::cin >> n;
  std::vector<int> as(n);
  for (unsigned int i = 0; i < n; ++i) {
    std::cin >> as[i];
  }
  auto q = partition(as, 0, n - 1);
  print_partition_ints(as, q);
}