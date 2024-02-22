#include <iostream>
#include <algorithm>
#include <iterator>

template <class RandomAccessIterator, class Compare>
void hsort(RandomAccessIterator first, RandomAccessIterator last, Compare cmp) {
  std::make_heap(first, last, cmp);
  std::sort_heap(first, last, cmp);
}

template <class RandomAccessIterator>
void hsort(RandomAccessIterator first, RandomAccessIterator last) {
  hsort(first, last, std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>());
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  int* a = new int[n];
  for (int i = 0; i < n; i++)
    std::cin >> a[i];

  hsort(a, a + n);

  std::copy(a, a + n, std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  delete[] a;

  return 0;
}