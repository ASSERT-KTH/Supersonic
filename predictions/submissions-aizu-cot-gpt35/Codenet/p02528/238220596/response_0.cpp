#include <iostream>

template <class T, class Compare>
void hsort(T& a, std::size_t n, const Compare& cmp) {
  if (n < 2) {
    return;
  }

  auto heapify = [&](T& a, std::size_t p, std::size_t hpsz, const Compare& cmp) {
    while (true) {
      std::size_t c = (p << 1) + 1;
      if (c >= hpsz) {
        break;
      }
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

  for (std::size_t i = n / 2; i > 0; --i) {
    heapify(a, i - 1, n, cmp);
  }

  for (std::size_t i = n; i > 1; --i) {
    std::swap(a[0], a[i - 1]);
    heapify(a, 0, i - 1, cmp);
  }
}

template <class Iterator, class Compare>
void hsort(Iterator a0, Iterator aN, const Compare& cmp) {
  using val_t = typename std::iterator_traits<Iterator>::value_type;
  using dif_t = typename std::iterator_traits<Iterator>::difference_type;
  dif_t n = std::distance(a0, aN);
  hsort(a0, static_cast<std::size_t>(n), cmp);
}

template <class Iterator>
void hsort(Iterator a0, Iterator aN) {
  hsort(a0, aN, std::less<typename std::iterator_traits<Iterator>::value_type>());
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  static int a[1000000];
  for (auto& value : a) {
    std::cin >> value;
  }

  hsort(a, a + n);

  for (int i = 0; i < n; i++) {
    std::cout << a[i] << ((i == n - 1) ? '\n' : ' ');
  }

  return 0;
}