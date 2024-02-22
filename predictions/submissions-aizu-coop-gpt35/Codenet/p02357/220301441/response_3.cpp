#include <iostream>
#include <vector>
#include <cstdint>

template <typename T>
class StaticRMQ {
  std::vector<T> a;

public:
  StaticRMQ(std::vector<T>& array) {
    a = array;
  }

  T operator()(uint32_t begin, uint32_t end) {
    T min_val = a[begin];
    for (uint32_t i = begin + 1; i <= end; ++i) {
      if (a[i] < min_val) {
        min_val = a[i];
      }
    }
    return min_val;
  }
};

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  uint32_t n, l;
  std::cin >> n >> l;

  std::vector<uint32_t> a(n);
  for (uint32_t i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  StaticRMQ<uint32_t> S(a);

  std::cout << S(0, l);
  for (uint32_t i = 1; i < n - l + 1; ++i) {
    std::cout << " " << S(i, i + l);
  }
  std::cout << "\n";

  return 0;
}