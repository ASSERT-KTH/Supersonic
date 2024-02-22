#include <iostream>
#include <vector>
#include <memory>
using namespace std;

const int divisor = 1000000007;

int main() {
  vector<long long> factorial(100001);

  // Precalculate factorials
  long long fact = 1;
  for (int i = 1; i <= 100000; i++) {
    fact *= i;
    fact %= divisor;
    factorial[i] = fact;
  }

  vector<int> word(100000);

  while (true) {
    int N, R;
    cin >> N;
    if (N == 0)
      break;
    cin >> R;

    // Initialize word array
    for (int i = 0; i < N; i++)
      word[i] = i + 1;

    for (int i = 0; i < R; i++) {
      int s, t;
      cin >> s >> t;
      int tmp = word[s - 1];
      word[s - 1] = word[t - 1];
      word[t - 1] = tmp;
    }

    vector<int> bubblehist(N + 1, 0);
    long long ans = factorial[N - 1] * (word[0] - 1);

    for (int i = 1; i < N; i++) {
      int facttime = word[i] - 1;
      int bubblenum;

      // Find bubble number
      for (int j = word[i]; j <= N; j++) {
        if (bubblehist[j] > 0) {
          bubblenum = bubblehist[j];
          break;
        }
      }

      // Update bubble history
      for (int j = word[i]; j <= N; j++)
        bubblehist[j]++;

      facttime -= bubblenum;
      ans += factorial[N - (i + 1)] * facttime;
      ans %= divisor;
    }

    cout << static_cast<int>(ans) << "\n";
  }

  return 0;
}