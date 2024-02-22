#include <iostream>
#include <algorithm>

const int divisor = 1000000007;

int main() {
  long long fact = 1;
  int word[100000]{0};

  for (int i = 1; i <= 100000; i++) {
    fact = (fact * i) % divisor;
  }

  while (true) {
    int N, R;
    std::cin >> N;
    if (N == 0) {
      break;
    }
    std::cin >> R;

    for (int i = 0; i < N; i++) {
      word[i] = i + 1;
    }

    for (int i = 0; i < R; i++) {
      int s, t;
      std::cin >> s >> t;
      std::swap(word[s - 1], word[t - 1]);
    }

    int bubblehist[100001] = {0};
    long long ans = fact * (word[0] - 1) % divisor;
    bubblehist[word[0]] = 0;

    for (int i = 1; i < N; i++) {
      int facttime = word[i] - 1;
      int bubblenum = bubblehist[word[i]] == 0 ? bubblehist[word[i] - 1] + 1 : bubblehist[word[i]];
      bubblehist[word[i]] = bubblenum;
      
      for (int j = word[i] + 1; j <= N; j++) {
        bubblehist[j]++;
      }

      facttime -= bubblenum;
      ans = (ans + ((fact * facttime) % divisor)) % divisor;
      fact = (fact * (N - i)) % divisor;
    }

    std::cout << static_cast<int>(ans) << "\n";
  }

  return 0;
}