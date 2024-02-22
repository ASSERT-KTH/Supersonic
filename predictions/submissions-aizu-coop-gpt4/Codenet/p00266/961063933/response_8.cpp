#include <iostream>
#include <unordered_map>
using namespace std;
const int divisor = 1000000007;
int main() {
  long long factmodary[100001];
  long long fact = 1;
  for (int i = 1; i <= 100000; i++) {
    fact *= i;
    fact %= divisor;
    factmodary[i] = fact;
  }
  int word[100000] = {0};
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
    unordered_map<int, int> bubblehist;
    bubblehist[word[0]] = 0;
    long long ans = factmodary[N - 1] * (word[0] - 1);
    for (int i = 1; i < N; i++) {
      int facttime = word[i] - 1;
      int bubblenum;
      unordered_map<int, int>::iterator it = bubblehist.find(word[i]);
      if (it != bubblehist.end()) {
        bubblenum = it->second;
      }
      else {
        bubblenum = (++bubblehist.rbegin())->second + 1;
      }
      bubblehist[word[i]] = bubblenum;
      facttime -= bubblenum;
      ans += factmodary[N - (i + 1)] * facttime;
      ans %= divisor;
    }
    cout << ans << "\n";
  }
  return 0;
}