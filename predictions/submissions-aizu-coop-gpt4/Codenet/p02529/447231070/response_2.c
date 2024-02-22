#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> numbers(n);
  for(int i = 0; i < n; ++i) {
    std::cin >> numbers[i];
  }

  std::unordered_map<int, int> count_map;
  for(int num : numbers) {
    count_map[num]++;
  }

  int d = 0;
  std::cin >> n;
  for(int i = 0; i < n; ++i) {
    int b;
    std::cin >> b;
    d += count_map[b];
  }

  std::cout << d << '\n';

  return 0;
}