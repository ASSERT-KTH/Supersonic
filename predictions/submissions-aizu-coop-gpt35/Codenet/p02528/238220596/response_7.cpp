#include <iostream>
#include <vector>
#include <utility>

template <class T, class Compare>
void heapify(std::vector<T>& a, std::ptrdiff_t p, std::ptrdiff_t hpsz, Compare cmp) {
  std::ptrdiff_t c;
  T temp = std::move(a[p]); // Store the value at index p in a temporary variable
  while ((c = (p << 1) + 1) < hpsz) {
    if (c + 1 < hpsz && cmp(a[c], a[c + 1])) {
      ++c;
    }
    if (!cmp(temp, a[c])) {
      break;
    }
    a[p] = std::move(a[c]); // Move the value at index c to index p
    p = c;
  }
  a[p] = std::move(temp); // Move the temporary variable to the final position
}

template <class T, class Compare>
void hsort(std::vector<T>& a, Compare cmp) {
  std::ptrdiff_t n = a.size();
  for (std::ptrdiff_t i = n / 2; i >= 0; --i) {
    heapify(a, i, n, cmp);
  }
  for (std::ptrdiff_t i = n - 1; i > 0; --i) {
    std::swap(a[0], a[i]);
    heapify(a, 0, i, cmp);
  }
}

template <class Iterator, class Compare>
void hsort(Iterator a0, Iterator aN, Compare cmp) {
  using dif_t = typename std::iterator_traits<Iterator>::difference_type;
  dif_t n = std::distance(a0, aN);
  std::vector<typename std::iterator_traits<Iterator>::value_type> a(a0, aN);
  hsort(a, cmp);
  std::copy(a.begin(), a.end(), a0);
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
  std::vector<int> a(n);
  for (int i = 0; i < n; i++)
    std::cin >> a[i];
  hsort(a.begin(), a.end());
  for (int i = 0; i < n; i++)
    std::cout << a[i] << ((i == n - 1) ? '\n' : ' ');
  return 0;
}