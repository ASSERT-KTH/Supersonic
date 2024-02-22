#include <iostream>
#include <vector>
using namespace std;

const int divisor = 1000000007;

int main() {
  long long factmodary[100001];
  factmodary[0] = 1;
  for (int i = 1; i <= 100000; i++) {
    factmodary[i] = (factmodary[i - 1] * i) % divisor;
  }

  vector<int> word(100000, 0);

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
      word[s - 1] ^= word[t - 1];
      word[t - 1] ^= word[s - 1];
      word[s - 1] ^= word[t - 1];
    }
    int bubblehist[100000] = {0};
    bubblehist[word[0]]++;
    long long ans = factmodary[N - 1] * (word[0] - 1);
    int bubblenum = 0;
    for (int i = 1; i < N; i++) {
      for (int j = word[i] + 1; j < 100000; j++) {
        bubblenum += bubblehist[j];
      }
      bubblehist[word[i]] = bubblenum;
      for (int j = word[i] + 1; j < 100000; j++) {
        bubblehist[j]++;
      }
      int facttime = word[i] - 1;
      ans += factmodary[N - (i + 1)] * facttime;
      ans %= divisor;
    }
    cout << static_cast<int>(ans) << "\n";
  }

  return 0;
}