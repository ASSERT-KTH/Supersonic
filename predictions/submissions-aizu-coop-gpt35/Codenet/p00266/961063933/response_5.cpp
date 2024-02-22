#include <iostream>
#include <array>
using namespace std;

const int divisor = 1000000007;
const int maxN = 100000;

// Pre-compute and store the factorial modulo divisor values
array<long long, maxN + 1> factmodary;

// Pre-compute and store the values for N - 1 and N - (i + 1)
array<long long, maxN + 1> factmodaryNMinus1;
array<long long, maxN + 1> factmodaryNMinusIPlus1;

void precomputeFactorialModulo() {
  long long fact = 1;
  for (int i = 1; i <= maxN; i++) {
    fact *= i;
    fact %= divisor;
    factmodary[i] = fact;
    factmodaryNMinus1[i] = factmodary[i - 1];
    factmodaryNMinusIPlus1[i] = factmodary[maxN - i];
  }
}

int main() {
  precomputeFactorialModulo();

  // Use stack-allocated arrays instead of dynamic allocation
  int word[maxN]{0};

  for (;;) {
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
      int tmp = word[s - 1];
      word[s - 1] = word[t - 1];
      word[t - 1] = tmp;
    }

    // Use a stack-allocated array instead of a map
    array<int, maxN> bubblehist{};
    bubblehist[word[0]] = 0;

    long long ans = factmodaryNMinus1[N - 1] * (word[0] - 1) % divisor;

    for (int i = 1; i < N; i++) {
      int facttime = word[i] - 1;
      int bubblenum = 0;
      for (int j = 1; j < word[i]; j++) {
        bubblenum += bubblehist[j];
      }
      bubblehist[word[i]]++;
      for (int j = word[i] + 1; j <= N; j++) {
        bubblehist[j]++;
      }
      facttime -= bubblenum;
      ans += factmodaryNMinusIPlus1[i] * facttime % divisor;
      ans %= divisor;
    }
    cout << static_cast<int>(ans) << "\n";
  }
  return 0;
}