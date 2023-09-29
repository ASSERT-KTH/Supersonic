#include <iostream>
#include <map>
using namespace std;
const int divisor = 1000000007;
const int MAXN = 100000;
long long factmodary[MAXN+1]; // Use a constant instead of a variable for the size
int word[MAXN];
int main() {
  long long fact = 1;
  for (int i = 1; i <= MAXN; i++) {
    fact = (fact * i) % divisor; // Combine multiplication and modulo operation
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
      swap(word[s - 1], word[t - 1]); // Use swap instead of temporary variable
    }
    map<int, int> bubblehist;
    bubblehist[word[0]] = 0;
    long long ans = factmodary[N - 1] * (word[0] - 1);
    for (int i = 1; i < N; i++) {
      int facttime = word[i] - 1, bubblenum;
      auto it = bubblehist.lower_bound(word[i]);
      if (it != bubblehist.end()) {
        bubblenum = it->second;
        it--;
      } else {
        it--;
        bubblenum = it->second + 1;
      }
      auto [it2, inserted] = bubblehist.insert({word[i], bubblenum});
      for (++it2; it2 != bubblehist.end(); it2++)
        (it2->second)++;
      facttime -= bubblenum;
      ans = (ans + factmodary[N - (i + 1)] * facttime) % divisor; // Combine addition and modulo operation
    }
    cout << ans << "\n";
  }
  return 0;
}