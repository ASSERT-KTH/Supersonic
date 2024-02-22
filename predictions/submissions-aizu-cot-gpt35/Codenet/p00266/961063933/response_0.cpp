#include <iostream>
#include <vector>
using namespace std;

const int divisor = 1000000007;

int main() {
  int maxN = 0;
  vector<long long> factmodary;
  
  long long fact = 1;
  for (int i = 1; i <= 100000; i++) {
    fact *= i;
    fact %= divisor;
    if (i > maxN) {
      factmodary.push_back(fact);
      maxN = i;
    }
  }

  int maxWord = 0;
  vector<int> word;

  while (true) {
    int N, R;
    scanf("%d", &N);
    if (N == 0)
      break;
    scanf("%d", &R);

    if (N > maxWord) {
      word.resize(N);
      for (int i = 0; i < N; i++)
        word[i] = i + 1;
      maxWord = N;
    } else {
      for (int i = 0; i < N; i++)
        word[i] = i + 1;
    }

    for (int i = 0; i < R; i++) {
      int s, t;
      scanf("%d %d", &s, &t);
      int tmp = word[s - 1];
      word[s - 1] = word[t - 1];
      word[t - 1] = tmp;
    }

    vector<int> bubblehist(maxWord + 1);
    bubblehist[word[0]] = 0;
    long long ans = factmodary[N - 1] * (word[0] - 1) % divisor;
    
    for (int i = 1; i < N; i++) {
      int facttime = word[i] - 1;
      int bubblenum = bubblehist[word[i]] > 0 ? bubblehist[word[i]] : bubblehist[word[i] - 1] + 1;
      bubblehist[word[i]] = bubblenum;

      for (int j = word[i] + 1; j <= maxWord; j++)
        bubblehist[j]++;

      facttime -= bubblenum;
      ans += factmodary[N - (i + 1)] * facttime % divisor;
      ans %= divisor;
    }

    printf("%d\n", (int)ans);
  }

  return 0;
}