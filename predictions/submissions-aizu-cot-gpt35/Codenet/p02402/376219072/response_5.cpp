#include <algorithm>
#include <iostream>

int main() {
  int n;
  std::cin >> n;

  long long* a = new long long[n];

  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  long long min = a[0];
  long long max = a[0];
  long long sum = 0;

  for (int i = 0; i < n; i++) {
    if (a[i] < min) {
      min = a[i];
    }
    if (a[i] > max) {
      max = a[i];
    }
    sum += a[i];
  }

  std::cout << min << " " << max << " " << sum << std::endl;

  delete[] a;

  return 0;
}