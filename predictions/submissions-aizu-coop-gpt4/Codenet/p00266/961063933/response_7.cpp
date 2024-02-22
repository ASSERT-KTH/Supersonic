#include <iostream>
using namespace std;

const int divisor = 1000000007;

long long factmodary[100001];
int word[100000];
int bubblehist[100001];

int main() {
  long long fact = 1;
  factmodary[0] = 1;
  for (int i = 1; i <= 100000; i++) {
    fact = (fact * i) % divisor;
    factmodary[i] = fact;
  }

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
      swap(word[s - 1], word[t - 1]);
    }

    for (int i = 0; i <= N; i++)
      bubblehist[i] = 0;

    bubblehist[word[0]] = 1;
    long long ans = factmodary[N - 1] * (word[0] - 1) % divisor;

    for (int i = 1; i < N; i++) {
      bubblehist[word[i]] = 1;
      int bubblenum = 0;
      for (int j = 1; j < word[i]; j++)
        bubblenum += bubblehist[j];

      int facttime = word[i] - 1 - bubblenum;
      ans = (ans + factmodary[N - i - 1] * facttime % divisor) % divisor;
    }

    cout << ans << "\n";
  }

  return 0;
}