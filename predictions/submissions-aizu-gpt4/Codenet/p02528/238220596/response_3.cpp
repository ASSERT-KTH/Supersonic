#include <iostream>
#include <algorithm>
template <class T, class Compare>
void hsort(T a, std::ptrdiff_t n, Compare cmp) {
  std::make_heap(a, a+n, cmp);
  std::sort_heap(a, a+n, cmp);
}
template <class Iterator, class Compare>
void hsort(Iterator a0, Iterator aN, Compare cmp) {
  hsort(a0, std::distance(a0, aN), cmp);
}
template <class Iterator> void hsort(Iterator a0, Iterator aN) {
  using val_t = typename std::iterator_traits<Iterator>::value_type;
  hsort(a0, aN, std::less<val_t>());
}
int main(void) {
  using namespace std;
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  static int a[1000000];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  hsort(a, a + n);
  for (int i = 0; i < n; i++)
    cout << a[i] << ((i == n - 1) ? '\n' : ' ');
  return 0;
}