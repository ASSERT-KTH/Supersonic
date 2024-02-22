#include <iostream>
#include <utility>
template <class T, class Compare>
void hsort(T a, std::ptrdiff_t n, Compare cmp) {
  if (n < 2) {
    return;
  }
  using dif_t = std::ptrdiff_t;
  auto heapify = [](T a, dif_t p, dif_t hpsz, Compare cmp) {
    while (true) {
      dif_t c = (p << 1) + 1;
      if (c < hpsz) {
        if (c + 1 < hpsz && cmp(a[c], a[c + 1])) {
          ++c;
        }
        if (!cmp(a[p], a[c])) {
          break;
        }
        std::swap(a[p], a[c]);
        p = c;
      } else {
        break;
      }
    }
  };
  for (dif_t i = n / 2; i >= 0; --i) {
    heapify(a, i, n, cmp);
  }
  for (dif_t i = n - 1; i > 0; --i) {
    std::swap(a[0], a[i]);
    heapify(a, 0, i, cmp);
  }
}
template <class Iterator, class Compare>
void hsort(Iterator a0, Iterator aN, Compare cmp) {
  using dif_t = typename std::iterator_traits<Iterator>::difference_type;
  dif_t n = std::distance(a0, aN);
  hsort(a0, n, cmp);
}
template <class Iterator> void hsort(Iterator a0, Iterator aN) {
  using val_t = typename std::iterator_traits<Iterator>::value_type;
  hsort(a0, aN, std::less<val_t>());
}
int main(void) {
  using namespace std;
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int* a = new int[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  hsort(a, a + n);
  for (int i = 0; i < n; i++)
    cout << a[i] << ((i == n - 1) ? '\n' : ' ');
  delete [] a;
  return 0;
}