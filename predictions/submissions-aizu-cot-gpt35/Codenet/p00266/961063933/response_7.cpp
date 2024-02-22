#include <iostream>
#include <map>
using namespace std;

static const int divisor = 1000000007;

int main() {
  static long long factmodary[100001];
  static int word[100000]{0};

  ios_base::sync_with_stdio(false);

  long long fact = 1;
  for (int i = 1; i <= 100000; i++) {
    fact *= i;
    if (fact >= divisor)
      fact %= divisor;
    factmodary[i] = fact;
  }

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

    static int bubblehist[100001];
    for (int i = 0; i <= N; i++)
      bubblehist[i] = 0;

    bubblehist[word[0]] = 0;
    long long ans = factmodary[N - 1] * (word[0] - 1);

    for (int i = 1; i < N; i++) {
      int facttime = word[i] - 1;
      int bubblenum = bubblehist[word[i]];
      bubblehist[word[i]]++;
      for (int j = word[i] + 1; j <= N; j++)
        bubblehist[j]++;
      facttime -= bubblenum;
      ans += factmodary[N - (i + 1)] * facttime;
      if (ans >= divisor)
        ans %= divisor;
    }

    cout << (int)ans << "\n";
  }

  return 0;
}