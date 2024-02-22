#include <iostream>
using namespace std;
const int divisor = 1000000007;

int main() {
  #pragma GCC optimize("unroll-loops")
  for (;;) {
    int N, R;
    cin >> N;
    if (N == 0)
      break;
    cin >> R;
    int* word = new int[N];
    for (int i = 0; i < N; i++)
      word[i] = i + 1;
    for (int i = 0; i < R; i++) {
      int s, t;
      cin >> s >> t;
      int tmp = word[s - 1];
      word[s - 1] = word[t - 1];
      word[t - 1] = tmp;
    }
    int* bubblehist = new int[N + 1]{0};
    bubblehist[word[0]] = 0;
    long long ans = (word[0] - 1);
    long long factmod = (N - 1);
    ans %= divisor;
    for (int i = 1; i < N; i++) {
      int facttime = word[i] - 1;
      int bubblenum;
      if (word[i] <= N && bubblehist[word[i]] != 0) {
        bubblenum = bubblehist[word[i]];
      } else {
        bubblenum = bubblehist[word[i] - 1] + 1;
      }
      bubblehist[word[i]] = bubblenum;
      for (int j = word[i] + 1; j <= N; j++)
        (bubblehist[j])++;
      facttime -= bubblenum;
      ans += factmod * facttime;
      ans %= divisor;
      factmod = (factmod * (N - (i + 1))) % divisor;
    }
    cout << (int)ans << "\n";
    delete[] word;
    delete[] bubblehist;
  }
  return 0;
}