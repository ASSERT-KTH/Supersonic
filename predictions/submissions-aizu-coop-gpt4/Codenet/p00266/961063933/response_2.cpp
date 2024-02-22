#include <iostream>
#include <vector>
using namespace std;
const int divisor = 1000000007;
int main() {
  long long *factmodary = new long long[100001];
  long long fact = 1;
  for (int i = 1; i <= 100000; i++) {
    fact *= i;
    fact %= divisor;
    factmodary[i] = fact;
  }
  int *word = new int[100000]{0};
  for (;;) {
    int N, R;
    cin >> N;
    if (N == 0)
      break;
    cin >> R;
    vector<int> index(N);
    for (int i = 0; i < N; i++)
      word[i] = index[i] = i + 1;
    for (int i = 0; i < R; i++) {
      int s, t;
      cin >> s >> t;
      swap(index[s - 1], index[t - 1]);
    }
    vector<int> bubblehist(N + 1, 0);
    long long ans = factmodary[N - 1] * (word[index[0] - 1] - 1);
    for (int i = 1; i < N; i++) {
      int facttime = word[index[i] - 1] - 1;
      int bubblenum = bubblehist[word[index[i] - 1]];
      bubblehist[word[index[i] - 1]]++;
      facttime -= bubblenum;
      ans += factmodary[N - (i + 1)] * facttime;
      ans %= divisor;
    }
    cout << (int)ans << "\n";
  }
  delete[] word;
  delete[] factmodary;
  return 0;
}