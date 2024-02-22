#include <algorithm>
#include <cstdio>
using uint = unsigned int;

static void print_partition_ints(const int as[], const uint q, const uint n) {
  std::string output;
  for (auto i = 0u; i < n; ++i) {
    if (i != q) {
      output += std::to_string(as[i]) + " ";
    } else {
      output += "[" + std::to_string(as[i]) + "] ";
    }
  }
  std::printf("%s\n", output.c_str());
}

static uint partition(int as[], const uint first, const uint last) {
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
  uint n;
  std::scanf("%u", &n);
  int* as = new int[n];
  for (auto i = 0u; i < n; ++i) {
    std::scanf("%d", &as[i]);
  }
  auto q = partition(as, 0, n - 1);
  print_partition_ints(as, q, n);
  delete[] as;
  return 0;
}