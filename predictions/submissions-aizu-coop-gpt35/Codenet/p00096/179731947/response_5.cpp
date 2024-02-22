#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<unsigned long long> cur(4001, 0);
  std::vector<unsigned long long> prev(4001, 0);

  cur[0] = 1;
  prev[0] = 1;

  for (int j = 1; j <= 1000; j++) {
    cur[j] = 1;
    prev[j] = 1;
  }

  for (int i = 2; i <= 4; i++) {
    std::swap(cur, prev);
    std::fill(cur.begin(), cur.end(), 0);
    for (int j = 0; j <= 4000; j++) {
      for (int k = 0; k <= std::min(j, 1000); k++) {
        cur[j] += prev[j - k];
      }
    }
  }

  int n;
  while (std::cin >> n) {
    std::cout << cur[n] << std::endl;
  }

  return 0;
}