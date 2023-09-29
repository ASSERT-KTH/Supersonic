#include <iostream>
#include <algorithm>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  int* a = new int[n];
  
  for (int i = 0; i < n; i++)
    std::cin >> a[i];

  std::sort(a, a + n);

  for (int i = 0; i < n; i++)
    std::cout << a[i] << ((i == n - 1) ? '\n' : ' ');

  delete[] a;
  
  return 0;
}