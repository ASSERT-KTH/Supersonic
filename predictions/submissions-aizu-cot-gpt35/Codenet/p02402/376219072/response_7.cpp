#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  int min_num = INT_MAX;
  int max_num = INT_MIN;
  long long sum = 0;

  for (int i = 0; i < n; i++) {
    int num;
    std::cin >> num;

    min_num = std::min(min_num, num);
    max_num = std::max(max_num, num);
    sum += num;
  }

  std::cout << min_num << " " << max_num << " " << sum << std::endl;
}