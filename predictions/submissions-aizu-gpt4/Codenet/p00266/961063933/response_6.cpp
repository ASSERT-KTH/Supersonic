#include <iostream>
#include <vector>
#include <algorithm>
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
    if (N == 0)
      break;
    cin >> R;
    iota(word.begin(), word.begin() + N, 1);
    for (int i = 0; i < R; i++) {
      int s, t;
      cin >> s >> t;
      swap(word[s - 1], word[t - 1]);
    }

    long long ans = 0;
    vector<int> rank(N);
    for (int i = 0; i < N; ++i) {
      rank[word[i] - 1] = i;
    }
    for (int i = 0; i < N; ++i) {
      ans = (ans + (rank[i] * factmodary[N - i - 1]) % divisor) % divisor;
    }
    cout << ans << "\n";
  }
  return 0;
}