#include <iostream>
#include <map>
using namespace std;
const int divisor = 1000000007;
const int maxN = 100000;
long long factmodary[maxN + 1];
int word[maxN];
int main() {
  long long fact = 1;
  for (int i = 1; i <= maxN; i++) {
    fact *= i;
    fact %= divisor;
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
    map<int, int> bubblehist;
    bubblehist[word[0]] = 0;
    long long ans = factmodary[N - 1] * (word[0] - 1);
    for (int i = 1; i < N; i++) {
      int facttime = word[i] - 1;
      int bubblenum;
      auto it = bubblehist.lower_bound(word[i]);
      if (it != bubblehist.end()) {
        bubblenum = it->second;
        it--;
      } else {
        it--;
        bubblenum = it->second + 1;
      }
      auto [it2, success] = bubblehist.insert({word[i], bubblenum});
      it2++;
      for (; it2 != bubblehist.end(); it2++)
        (it2->second)++;
      facttime -= bubblenum;
      ans += factmodary[N - (i + 1)] * facttime;
      ans %= divisor;
    }
    cout << (int)ans << "\n";
  }
  return 0;
}