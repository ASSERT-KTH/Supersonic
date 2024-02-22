#include <iostream>
#include <vector>
#include <sstream>

const int MAX_N = 300000;

int main() {
  std::vector<int> lists;
  std::vector<bool> checked(MAX_N + 1, false);
  for (int i = 2; i <= MAX_N; i++) {
    if (checked[i])
      continue;
    if (i % 7 == 1 || i % 7 == 6) {
      lists.push_back(i);
      int k = 1;
      while (i * k <= MAX_N) {
        checked[i * k] = true;
        k++;
      }
    }
  }
  int n;
  do {
    std::cin >> n;
    if (n == 1)
      break;
    std::vector<int> ans;
    std::copy_if(lists.begin(), lists.end(), std::back_inserter(ans), [&](int p) {
      return n % p == 0;
    });
    std::stringstream ss;
    ss << n << ':';
    for (int i : ans) {
      ss << ' ' << i;
    }
    std::cout << ss.str() << std::endl;
  } while (true);

  return 0;
}