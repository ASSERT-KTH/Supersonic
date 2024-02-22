#include <iostream>
#include <algorithm>

int main() {
  int a, b, c, d, e, f;
  std::cin >> a >> b >> c >> d >> e >> f;
  
  int arr[4] = {a, b, c, d};
  int* minElement = std::min_element(arr, arr + 4);
  int* maxElement = std::max_element(&e, &f + 1);
  int ans = a + b + c + d - *minElement + *maxElement;

  std::cout << ans << std::endl;
  return 0;
}