#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <iterator>

template <class T, class Compare>
void heapify(T& a, std::ptrdiff_t p, std::ptrdiff_t hpsz, Compare cmp) {
  using dif_t = std::ptrdiff_t;
  dif_t c;
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

template <class Iterator, class Compare>
void hsort(Iterator a0, Iterator aN, Compare cmp) {
  using dif_t = typename std::iterator_traits<Iterator>::difference_type;
  dif_t n = std::distance(a0, aN);
  for (dif_t i = n / 2; i >= 0; --i) {
    heapify(a0, i, n, cmp);
  }
  for (dif_t i = n - 1; i > 0; --i) {
    std::swap(a0[0], a0[i]);
    heapify(a0, 0, i, cmp);
  }
}

template <class Iterator>
void hsort(Iterator a0, Iterator aN) {
  using val_t = typename std::iterator_traits<Iterator>::value_type;
  hsort(a0, aN, std::less<val_t>());
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(0);
  
  int n;
  std::cin >> n;
  
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  
  hsort(a.begin(), a.end());
  
  std::copy(a.begin(), a.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << '\n';
  
  return 0;
}