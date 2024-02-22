#include <iostream>
#include <algorithm>
using namespace std;
const int divisor = 1000000007;
int main() {
  long long *factmodary = new long long[100001];
  long long fact = 1;
  for (int i = 1; i <= 100000; i++) {
    fact = (fact * i) % divisor;
    factmodary[i] = fact;
  }
  int *word = new int[100000]{0};
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
      std::swap(word[s - 1], word[t - 1]);
    }
    int *bubblehist = new int[100001]{0};
    long long ans = (factmodary[N - 1] * (word[0] - 1)) % divisor;
    bubblehist[word[0]] = 0;
    for (int i = 1; i < N; i++) {
      ans += (factmodary[N - (i + 1)] * (word[i] - 1 - bubblehist[word[i]])) % divisor;
      ans %= divisor;
      bubblehist[word[i]]++;
    }
    cout << ans << "\n";
    delete[] bubblehist;
  }
  delete[] word;
  delete[] factmodary;
  return 0;
}