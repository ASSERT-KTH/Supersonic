#include <iostream>
#include <unordered_map>
using namespace std;
const int divisor = 1000000007;
long long factmodary[100001] = {1};
int word[100000] = {0};
unordered_map<int, int> bubblehist;

long long factorial(int n) {
  if (n == 0 || n == 1)
    return 1;
  if (factmodary[n] != 0)
    return factmodary[n];
  else {
    factmodary[n] = (n * factorial(n - 1)) % divisor;
    return factmodary[n];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
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
    bubblehist.clear();
    bubblehist[word[0]] = 0;
    long long ans = factorial(N - 1) * (word[0] - 1);
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
      pair<int, int> p;
      p.first = word[i];
      p.second = bubblenum;
      auto it2 = bubblehist.insert(it, p);
      for (++it2; it2 != bubblehist.end(); it2++)
        (it2->second)++;
      facttime -= bubblenum;
      ans += factorial(N - (i + 1)) * facttime;
      ans %= divisor;
    }
    cout << (int)ans << "\n";
  }
  return 0;
}