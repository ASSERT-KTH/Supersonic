#include <iostream>
#include <algorithm>
#include <vector>
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
  vector<int> word(100000);
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
    vector<int> bubblehist(N + 1, 0);
    bubblehist[word[0]] = 0;
    long long ans = factmodary[N - 1] * (word[0] - 1);
    for (int i = 1; i < N; i++) {
      int facttime = word[i] - 1;
      int bubblenum = lower_bound(bubblehist.begin(), bubblehist.end(), word[i]) - bubblehist.begin();
      bubblehist[word[i]] = bubblenum;
      facttime -= bubblenum;
      ans += factmodary[N - (i + 1)] * facttime;
      ans %= divisor;
    }
    cout << (int)ans << "\n";
  }
  delete[] factmodary;
  return 0;
}