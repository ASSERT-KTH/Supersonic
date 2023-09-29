#include <iostream>
#include <vector>
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
    if (N == 0) break;
    cin >> R;
    for (int i = 0; i < N; i++) word[i] = i + 1;
    for (int i = 0; i < R; i++) {
      int s, t;
      cin >> s >> t;
      swap(word[s - 1], word[t - 1]);
    }
    vector<int> bubblehist(N);
    bubblehist[word[0]] = 0;
    long long ans = (factmodary[N - 1] * (word[0] - 1)) % divisor;
    for (int i = 1; i < N; i++) {
      int facttime = word[i] - 1;
      int bubblenum;
      auto it = lower_bound(bubblehist.begin(), bubblehist.end(), word[i]);
      if (it != bubblehist.end()) {
        bubblenum = *it;
        it--;
      } else {
        it--;
        bubblenum = *it + 1;
      }
      pair<int, int> p;
      p.first = word[i];
      p.second = bubblenum;
      auto it2 = bubblehist.insert(it, p.second);
      for (++it2; it2 != bubblehist.end(); it2++)
        (*it2)++;
      facttime -= bubblenum;
      ans += (factmodary[N - (i + 1)] * facttime);
      ans %= divisor;
    }
    cout << (int)ans << "\n";
  }
  return 0;
}