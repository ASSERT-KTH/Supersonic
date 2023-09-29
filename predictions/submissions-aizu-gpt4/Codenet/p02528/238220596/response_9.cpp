#include <iostream>
#include <algorithm>

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int n;
  std::cin >> n;
  static int a[1000000];
  for (int i = 0; i < n; i++)
    std::cin >> a[i];
  std::sort(a, a + n);
  for (int i = 0; i < n; i++)
    std::cout << a[i] << ((i == n - 1) ? '\n' : ' ');
  return 0;
}