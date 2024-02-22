#include <cstdio>
#include <map>
using namespace std;

const int divisor = 1000000007;
long long factmodary[100001];
int word[100000];

int main() {
  long long fact = 1;
  for (int i = 1; i <= 100000; i++) {
    fact *= i;
    fact %= divisor;
    factmodary[i] = fact;
  }
  for (;;) {
    int N, R;
    scanf("%d", &N);
    if (N == 0)
      break;
    scanf("%d", &R);
    for (int i = 0; i < N; i++)
      word[i] = i + 1;
    for (int i = 0; i < R; i++) {
      int s, t;
      scanf("%d%d", &s, &t);
      swap(word[s - 1], word[t - 1]);
    }
    map<int, int> bubblehist;
    bubblehist[word[0]] = 0;
    long long ans = factmodary[N - 1] * (word[0] - 1);
    for (int i = 1; i < N; i++) {
      int facttime = word[i] - 1;
      map<int, int>::iterator it = bubblehist.lower_bound(word[i]);
      int bubblenum = (it == bubblehist.end() ? (--it)->second + 1 : it->second);
      bubblehist[word[i]] = bubblenum;
      facttime -= bubblenum;
      ans += factmodary[N - (i + 1)] * facttime;
      ans %= divisor;
    }
    printf("%d\n", (int)ans);
  }
  return 0;
}