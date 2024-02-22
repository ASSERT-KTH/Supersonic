#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);

  int N, K, i, j, B;
  bool a;

  while (true) {
    std::cin >> N >> K;
    if (N == 0 && K == 0) {
      break;
    }

    std::vector<int> S(K);
    for (i = 0; i < K; ++i) {
      std::cin >> S[i];
    }

    a = true;
    for (i = 0; i < N; ++i) {
      for (j = 0; j < K; ++j) {
        std::cin >> B;
        S[j] -= B;
        if (S[j] < 0) {
          a = false;
        }
      }
    }

    std::cout << (a ? "Yes" : "No") << std::endl;
  }

  return 0;
}