#include <algorithm>
#include <cstdio>
#include <string>
using uint = unsigned int;

static void print_partition_ints(const int as[], const uint q, const uint n) {
  std::string formattedStr;
  for (auto i = 0u; i < n; ++i) {
    formattedStr += (i != q ? "%d " : "[%d] ");
  }
  formattedStr.pop_back(); // Remove trailing space
  std::printf((formattedStr + "\n").c_str(), as, as[n-1]);
}

static uint partition(int as[], const uint first, const uint last) {
  auto pivot = as[first];
  auto i = first - 1;
  auto j = last + 1;
  while (true) {
    do {
      ++i;
    } while (as[i] < pivot);
    do {
      --j;
    } while (as[j] > pivot);
    if (i >= j) {
      return j;
    }
    std::swap(as[i], as[j]);
  }
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
}