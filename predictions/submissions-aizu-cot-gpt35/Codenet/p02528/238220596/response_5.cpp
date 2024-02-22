#include <iostream>
#include <vector>
#include <algorithm>

template <class T, class Compare>
void hsort(T& a, std::ptrdiff_t n, Compare cmp) {
  if (n < 2) {
    return;
  }
  
  std::make_heap(a.begin(), a.end(), cmp);
  std::sort_heap(a.begin(), a.end(), cmp);
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
  using namespace std;
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  int n;
  cin >> n;
  
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  
  hsort(a.begin(), a.end());
  
  for (int i = 0; i < n; i++)
    cout << a[i] << ((i == n - 1) ? '\n' : ' ');
  
  return 0;
}