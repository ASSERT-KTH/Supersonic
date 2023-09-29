#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int divisor = 1000000007;
long long factmodary[100001];
int word[100000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long long fact = 1;
  for (int i = 1; i <= 100000; ++i) {
    fact *= i;
    fact %= divisor;
    factmodary[i] = fact;
  }
  
  while (true) {
    int N, R;
    cin >> N;
    if (N == 0)
      break;
    cin >> R;
    for (int i = 0; i < N; ++i)
      word[i] = i + 1;
    for (int i = 0; i < R; ++i) {
      int s, t;
      cin >> s >> t;
      swap(word[s - 1], word[t - 1]);
    }
    vector<int> bubblehist(N+1, 0);
    long long ans = factmodary[N - 1] * (word[0] - 1);
    for (int i = 1; i < N; ++i) {
      int facttime = word[i] - 1;
      int bubblenum = bubblehist[word[i]];
      bubblehist[word[i]] = i;
      facttime -= bubblenum;
      ans += factmodary[N - i] * facttime;
      ans %= divisor;
    }
    cout << ans << "\n";
  }
  return 0;
}