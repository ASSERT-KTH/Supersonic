#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int divisor = 1000000007;
int main() {
  vector<long long> factmodary(100001);
  long long fact = 1;
  for (int i = 1; i <= 100000; i++) {
    fact *= i;
    fact %= divisor;
    factmodary[i] = fact;
  }
  vector<int> word(100000);
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
    for (int i = 0; i < N; i++)
      bubblehist[word[i]]++;
    long long ans = 0;
    for (int i = 0; i < N; i++) {
      ans += factmodary[N - 1 - i] * (word[i] - bubblehist[word[i]]);
      ans %= divisor;
      bubblehist[word[i]]--;
    }
    cout << ans << "\n";
  }
  return 0;
}