#include <vector>
#include <string>
#include <cstdio>
using uint = unsigned int;

static void print_partition_ints(const std::vector<int>& as, const uint q, const uint n) {
  std::string out_str;
  for (uint i = 0; i < n; ++i) {
    char buffer[20];
    std::sprintf(buffer, (i != q ? "%d " : "[%d] "), as[i]);
    out_str += buffer;
  }
  std::printf("%s\n", out_str.c_str());
}

static uint partition(std::vector<int>& as, const uint first, const uint last) {
  uint less = first;
  for (uint i = first; i < last; ++i) {
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
  uint n;
  std::scanf("%u", &n);
  std::vector<int> as(n);
  for (uint i = 0; i < n; ++i) {
    std::scanf("%d", &as[i]);
  }
  const uint q = partition(as, 0, n - 1);
  print_partition_ints(as, q, n);
}