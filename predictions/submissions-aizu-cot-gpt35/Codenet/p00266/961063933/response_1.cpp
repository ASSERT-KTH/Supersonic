#include <iostream>
#include <vector>
#include <unordered_map>

const int divisor = 1000000007;

int main() {
  std::vector<long long> factmodary(100001);
  long long fact = 1;
  for (int i = 1; i <= 100000; i++) {
    fact = (fact * i) % divisor;
    factmodary[i] = fact;
  }

  std::vector<int> word(100000, 0);

  while (true) {
    int N, R;
    std::cin >> N;
    if (N == 0)
      break;
    std::cin >> R;

    for (int i = 0; i < N; i++)
      word[i] = i + 1;

    for (int i = 0; i < R; i++) {
      int s, t;
      std::cin >> s >> t;
      std::swap(word[s - 1], word[t - 1]);
    }

    std::unordered_map<int, int> bubblehist;
    bubblehist[word[0]] = 0;
    long long ans = factmodary[N - 1] * (word[0] - 1);

    for (int i = 1; i < N; i++) {
      int facttime = word[i] - 1;
      int bubblenum;
      auto it = bubblehist.lower_bound(word[i]);
      if (it != bubblehist.end()) {
        bubblenum = it->second;
        it--;
      } else {
        it--;
        bubblenum = it->second + 1;
      }
      auto p = std::make_pair(word[i], bubblenum);
      auto it2 = bubblehist.insert(it, p);
      for (++it2; it2 != bubblehist.end(); it2++)
        (it2->second)++;
      facttime -= bubblenum;
      ans = (ans + factmodary[N - (i + 1)] * facttime) % divisor;
    }

    std::cout << ans << "\n";
  }

  return 0;
}