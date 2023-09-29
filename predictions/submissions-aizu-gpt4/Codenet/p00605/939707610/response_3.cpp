#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int N, K, B;
  while (std::cin >> N >> K, N || K) {
    std::vector<int> S(K);
    for (auto &s : S)
      std::cin >> s;
    while (N--) {
      for (auto &s : S) {
        std::cin >> B;
        s -= B;
      }
    }
    std::cout << (std::all_of(S.begin(), S.end(), [](int s){ return s >= 0; }) ? "Yes" : "No") << std::endl;
  }
}