#include <algorithm>
#include <cstdio>

constexpr size_t MAXN = 1000000; // Maximum expected size of the array. Adjust as necessary.

static void print_partition_ints(const int as[], const unsigned int q, const unsigned int n) {
  auto out_sep = "";
  for (auto i = 0u; i < n; ++i) {
    auto format = (i != q ? "%s%d" : "%s[%d]");
    std::printf(format, out_sep, as[i]);
    out_sep = " ";
  }
  std::printf("\n");
}
static unsigned int partition(int as[], const unsigned int first, const unsigned int last) {
  auto less = first;
  for (auto i = first; i < last; ++i) {
    if (as[i] < as[last]) {
      std::swap(as[less++], as[i]);
    }
  }
  std::swap(as[less], as[last]);
  return less;
}
int main() {
  unsigned int n;
  std::scanf("%u", &n);
  int as[MAXN];
  for (auto i = 0u; i < n; ++i) {
    std::scanf("%d", &as[i]);
  }
  auto q = partition(as, 0, n - 1);
  print_partition_ints(as, q, n);
}