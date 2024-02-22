#include <cstdio>
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
  vector<int> counts(100001);
  for (;;) {
    int N, R;
    scanf("%d", &N);
    if (N == 0)
      break;
    scanf("%d", &R);
    for (int i = 0; i < N; i++)
      word[i] = i + 1;
    fill(counts.begin(), counts.end(), 0);
    for (int i = 0; i < R; i++) {
      int s, t;
      scanf("%d%d", &s, &t);
      swap(word[s - 1], word[t - 1]);
    }
    long long ans = 0;
    for (int i = N - 1; i >= 0; i--) {
      for (int j = word[i] + 1; j <= N; j++)
        counts[j]--;
      ans += factmodary[i] * counts[word[i]];
      ans %= divisor;
      counts[word[i]]++;
    }
    printf("%d\n", (int)ans);
  }
  return 0;
}