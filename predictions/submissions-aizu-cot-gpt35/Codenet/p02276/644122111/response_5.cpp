#include <cstdio>
#include <sstream>

static void print_partition_ints(const int as[], const std::size_t q, const std::size_t n) {
  std::stringstream ss;
  for (std::size_t i = 0; i < n; ++i) {
    if (i != q) {
      ss << as[i] << " ";
    } else {
      ss << "[" << as[i] << "] ";
    }
  }
  ss << "\n";
  std::printf("%s", ss.str().c_str());
}

static std::size_t partition(int as[], const std::size_t first, const std::size_t last) {
  std::size_t less = first;
  for (std::size_t i = first; i < last; ++i) {
    if (as[i] <= as[last]) {
      int temp = as[less];
      as[less] = as[i];
      as[i] = temp;
      ++less;
    }
  }
  int temp = as[less];
  as[less] = as[last];
  as[last] = temp;
  return less;
}

int main() {
  std::size_t n;
  std::scanf("%zu", &n);
  int as[n];
  for (std::size_t i = 0; i < n; ++i) {
    std::scanf("%d", &as[i]);
  }
  std::size_t q = partition(as, 0, n - 1);
  print_partition_ints(as, q, n);
  return 0;
}