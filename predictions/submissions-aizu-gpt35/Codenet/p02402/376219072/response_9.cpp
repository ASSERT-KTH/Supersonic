#include <algorithm>
#include <iostream>
#include <vector>
int main() {
  int n;
  std::vector<int> a;
  std::cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  int min = a[0], max = a[0], sum = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] < min) min = a[i];
    if (a[i] > max) max = a[i];
    sum += a[i];
  }
  std::cout << min << " " << max << " " << sum << std::endl;
}
