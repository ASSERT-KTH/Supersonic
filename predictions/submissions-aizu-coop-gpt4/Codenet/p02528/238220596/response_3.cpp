#include <iostream>
#include <vector>
#include <algorithm>

template <class T, class Compare>
void hsort(T& a, std::ptrdiff_t n, Compare cmp) {
  if (n < 2) {
    return;
  }
  using dif_t = std::ptrdiff_t;
  auto heapify = [&a](dif_t p, dif_t hpsz, Compare cmp) {
    dif_t c;
    while ((c = 2*p + 1) < hpsz) {
      if (c + 1 < hpsz && cmp(a[c], a[c + 1])) {
        ++c;
      }
      if (!cmp(a[p], a[c])) {
        break;
      }
      std::swap(a[p], a[c]);
      p = c;
    }
  };
  for (dif_t i = n / 2; i >= 0; --i) {
    heapify(i, n, cmp);
  }
  for (dif_t i = n - 1; i > 0; --i) {
    std::swap(a[0], a[i]);
    heapify(0, i, cmp);
  }
}

int main(void) {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++)
    std::cin >> a[i];
  hsort(a, n, std::less<int>());
  for (int i = 0; i < n; i++)
    std::cout << a[i] << ((i == n - 1) ? '\n' : ' ');
  return 0;
}