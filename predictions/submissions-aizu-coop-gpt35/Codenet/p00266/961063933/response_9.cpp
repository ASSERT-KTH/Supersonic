#include <iostream>
#include <vector>
using namespace std;

const int divisor = 1000000007;

int main() {
  const int maxN = 100000;
  vector<long long> factmodary(maxN + 1, 0);
  vector<int> word(maxN, 0);

  long long fact = 1;
  for (int i = 1; i <= maxN; i++) {
    fact *= i;
    fact %= divisor;
    factmodary[i] = fact;
  }

  while (true) {
    int N, R;
    cin >> N;
    if (N == 0)
      break;
    cin >> R;

    for (int i = 0; i < N; i++)
      word[i] = i + 1;

    for (int i = 0; i < R; i++) {
      int s, t;
      cin >> s >> t;
      swap(word[s - 1], word[t - 1]);
    }

    vector<int> bubblehist(N + 1, 0);
    long long ans = factmodary[N - 1] * (word[0] - 1);

    for (int i = 1; i < N; i++) {
      int facttime = word[i] - 1;
      int bubblenum = bubblehist[word[i]];
      bubblehist[word[i]]++;

      for (int j = word[i] + 1; j <= N; j++)
        bubblehist[j]++;

      facttime -= bubblenum;
      ans += factmodary[N - (i + 1)] * facttime;
      ans %= divisor;
    }

    cout << static_cast<int>(ans) << "\n";
  }

  return 0;
}