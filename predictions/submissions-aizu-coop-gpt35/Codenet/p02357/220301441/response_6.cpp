#include <cstdio>
#include <vector>

template <typename T>
class StaticRMQ {
  T *a;
  uint32 **table;

public:
  StaticRMQ(std::vector<T> &array) {
    uint32 n = array.size();
    uint32 logn = 32 - __builtin_clz(n);  // Compute the log base 2 of n

    // Initialize the static arrays
    table = new uint32 *[logn + 1];
    for (uint32 t = 0; t <= logn; ++t) {
      table[t] = new uint32[n];
    }

    // Initialize the first level of the sparse table
    for (uint32 i = 0; i < n; ++i) {
      table[0][i] = i;
    }

    // Compute the rest of the levels of the sparse table using binary lifting
    for (uint32 t = 1; t <= logn; ++t) {
      for (uint32 i = 0; i + (1 << t) <= n; ++i) {
        uint32 x = table[t - 1][i];
        uint32 y = table[t - 1][i + (1 << (t - 1))];
        table[t][i] = (array[x] < array[y]) ? x : y;
      }
    }

    a = new T[n];
    for (uint32 i = 0; i < n; ++i) {
      a[i] = array[i];
    }
  }

  T operator()(uint32 begin, uint32 end) {
    uint32 len = end - begin + 1;
    uint32 loglen = 31 - __builtin_clz(len);  // Compute the log base 2 of len

    uint32 x = table[loglen][begin];
    uint32 y = table[loglen][end - (1 << loglen) + 1];
    return std::min(a[x], a[y]);
  }
};

int main(void) {
  uint32 n, l;
  scanf("%u %u", &n, &l);

  std::vector<uint32> a(n);
  for (uint32 i = 0; i < n; ++i) {
    scanf("%u", &a[i]);
  }

  StaticRMQ<uint32> S(a);

  printf("%u", S(0, l));
  for (uint32 i = 1; i < n - l + 1; ++i) {