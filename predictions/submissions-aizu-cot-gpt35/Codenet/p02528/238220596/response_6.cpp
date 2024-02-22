#include <iostream>

template <class T, class Compare>
void hsort(T& a, std::size_t n, Compare cmp) {
  if (n < 2) {
    return;
  }
  auto heapify = [&](std::size_t p, std::size_t hpsz) {
    std::size_t c;
    while ((c = (p << 1) + 1) < hpsz) {
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
  for (std::ptrdiff_t i = n / 2; i >= 0; --i) {
    heapify(i, n);
  }
  for (std::ptrdiff_t i = n - 1; i > 0; --i) {
    std::swap(a[0], a[i]);
    heapify(0, i);
  }
}

template <class Iterator, class Compare>
void hsort(Iterator a0, Iterator aN, Compare cmp) {
  using dif_t = typename std::iterator_traits<Iterator>::difference_type;
  dif_t n = std::distance(a0, aN);
  hsort(*a0, n, cmp);
}

template <class Iterator>
void hsort(Iterator a0, Iterator aN) {
  using val_t = typename std::iterator_traits<Iterator>::value_type;
  hsort(*a0, std::distance(a0, aN), std::less<val_t>());
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);
  int n;
  std::cin >> n;
  int* a = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  hsort(a, a + n);
  for (int i = 0; i < n; i++) {
    std::cout << a[i] << ((i == n - 1) ? '\n' : ' ');
  }
  delete[] a;
  return 0;
}