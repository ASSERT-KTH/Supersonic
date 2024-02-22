#include <iostream>
#include <utility>
#include <algorithm>

template <class T, class Compare>
void heapify(T a, std::ptrdiff_t p, std::ptrdiff_t hpsz, Compare cmp) {
  std::ptrdiff_t c;
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
}

template <class T, class Compare>
void hsort(T a, std::ptrdiff_t n, Compare cmp) {
  if (n < 2) {
    return;
  }

  // Optimization: Use insertion sort for small inputs
  if (n < 32) {
    for (std::ptrdiff_t i = 1; i < n; ++i) {
      T key = a[i];
      std::ptrdiff_t j = i - 1;
      while (j >= 0 && cmp(key, a[j])) {
        a[j + 1] = a[j];
        --j;
      }
      a[j + 1] = key;
    }
    return;
  }

  std::make_heap(a, a + n, cmp);
  std::sort_heap(a, a + n, cmp);
}

template <class Iterator, class Compare>
void hsort(Iterator a0, Iterator aN, Compare cmp) {
  using dif_t = typename std::iterator_traits<Iterator>::difference_type;
  dif_t n = std::distance(a0, aN);
  hsort(a0, n, cmp);
}

template <class Iterator>
void hsort(Iterator a0, Iterator aN) {
  using val_t = typename std::iterator_traits<Iterator>::value_type;
  hsort(a0, aN, std::less<val_t>());
}

int main(void) {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);

  int n;
  std::cin >> n;

  static int a[1000000];
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  hsort(a, a + n);

  for (int i = 0; i < n; i++) {
    std::cout << a[i] << ((i == n - 1) ? '\n' : ' ');
  }

  return 0;
}