#include <iostream>
using namespace std;
const int divisor = 1000000007;
int main() {
  long long *factmodary = new long long[100001];
  long long fact = 1;
  for (int i = 1; i <= 100000; i++) {
    fact *= i;
    fact %= divisor;
    factmodary[i] = fact;
  }
  int *word = new int[100000]{0};
  int *bubblehist = new int[100001]{0};
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
    int totalCount = 0;
    long long ans = factmodary[N - 1] * (word[0] - 1);
    bubblehist[word[0]] = 1;
    totalCount++;
    for (int i = 1; i < N; i++) {
      int facttime = word[i] - 1;
      int bubblenum = bubblehist[word[i]];
      bubblehist[word[i]] = ++totalCount;
      facttime -= bubblenum;
      ans += factmodary[N - (i + 1)] * facttime;
      ans %= divisor;
    }
    cout << (int)ans << "\n";
    for (int i = 0; i < N; i++)
      bubblehist[word[i]] = 0;
  }
  delete[] word;
  delete[] factmodary;
  delete[] bubblehist;
  return 0;
}