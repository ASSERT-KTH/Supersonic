#include <iostream>
#include <utility>

template <class T, class Compare>
void heapify(T& a, std::ptrdiff_t p, std::ptrdiff_t hpsz, Compare cmp) {
  std::ptrdiff_t c;
  while ((c = (p * 2) + 1) < hpsz) {
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

int main(void) {
  using namespace std;
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin >> n;
  static int a[1000000];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  hsort(a, a + n, std::less<int>());

  for (int i = 0; i < n; i++)
    cout << a[i] << ((i == n - 1) ? '\n' : ' ');

  return 0;
}