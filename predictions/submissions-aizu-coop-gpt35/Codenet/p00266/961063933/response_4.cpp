#include <iostream>
using namespace std;

const unsigned int divisor = 1000000007;

int main() {
  unsigned int factmodary[100001];
  unsigned int fact = 1;

  // Calculate factorial values modulo divisor
  for (int i = 1; i <= 100000; i++) {
    fact = (fact * i) % divisor;
    factmodary[i] = fact;
  }
  
  int word[100000] = {0};
  
  while (true) {
    int N, R;
    cin >> N;
    if (N == 0)
      break;
    cin >> R;

    // Initialize word array
    for (int i = 0; i < N; i++)
      word[i] = i + 1;

    // Perform swap operations
    for (int i = 0; i < R; i++) {
      int s, t;
      cin >> s >> t;
      word[s - 1] ^= word[t - 1];
      word[t - 1] ^= word[s - 1];
      word[s - 1] ^= word[t - 1];
    }

    int bubblehist[100001] = {0};
    bubblehist[word[0]] = 0;
    unsigned int ans = (factmodary[N - 1] * (word[0] - 1)) % divisor;

    for (int i = 1; i < N; i++) {
      int facttime = word[i] - 1;
      int bubblenum = 0;
      for (int j = word[i] - 1; j >= 1; j--) {
        if (bubblehist[j] > 0) {
          bubblenum = bubblehist[j];
          break;
        }
      }
      bubblehist[word[i]] = bubblenum;
      for (int j = word[i] + 1; j <= N; j++)
        bubblehist[j]++;
      
      facttime -= bubblenum;
      ans = (ans + (factmodary[N - (i + 1)] * facttime) % divisor) % divisor;
    }

    cout << ans << "\n";
  }

  return 0;
}