#include <algorithm>
#include <iostream>

int main() {
  long long n, sum, current, max_sum;
  long long arr[99999];

  while (true) {
    std::cin >> n;
    if (n == 0)
      break;

    sum = 0;
    for (int i = 0; i < n; ++i) {
      std::cin >> current;
      sum += current;
      arr[i] = current;
    }

    std::sort(arr + 1, arr + n);

    max_sum = 0;
    for (int i = n; i > 0; --i) {
      sum += arr[i];
      max_sum = (i * sum > max_sum) ? i * sum : max_sum;
    }

    std::cout << max_sum << std::endl;
  }

  return 0;
}