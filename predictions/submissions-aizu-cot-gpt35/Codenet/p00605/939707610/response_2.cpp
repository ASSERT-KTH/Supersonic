#include <iostream>

int main() {
  int N, K, i, j, S[1000], B;
  while (std::cin >> N >> K, N || K) {
    for (i = K; i--;)
      std::cin >> S[i];
    for (i = 0; i < N; ++i) {
      for (j = K; j--;) {
        std::cin >> B;
        S[j] -= B;
        if (S[j] < 0) {
          i = N;
          break;
        }
      }
    }
    std::cout << (i == N ? "No" : "Yes") << std::endl;
  }
}