#include <iostream>

int main() {
  int N, K, i, j, S[100], B;
  while (std::cin >> N >> K, N || K) {
    for (i = 0; i < K; i++)
      std::cin >> S[i];
    bool a = true;
    for (i = 0; i < N; i++) {
      for (j = 0; j < K; j++) {
        std::cin >> B;
        S[j] -= B;
        if (S[j] < 0) {
          a = false;
          break;
        }
      }
    }
    std::cout << (a ? "Yes" : "No") << std::endl;
  }
}