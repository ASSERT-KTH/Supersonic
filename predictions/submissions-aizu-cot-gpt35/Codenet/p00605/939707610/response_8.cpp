#include <iostream>
#include <vector>

int main() {
  int N, K;
  while (std::cin >> N >> K, N || K) {
    std::vector<int> S(K);
    for (int i = 0; i < K; ++i)
      std::cin >> S[i];
      
    bool result = true;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < K; ++j) {
        int B;
        std::cin >> B;
        S[j] -= B;
        if (S[j] < 0) {
          result = false;
          break;
        }
      }
    }
    
    std::cout << (result ? "Yes" : "No") << std::endl;
  }
}