#include <iostream>
#include <map>
using namespace std;
const int divisor = 1000000007;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
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
    for (int i = 0; i < N; i++)
      word[i] = i + 1;
    for (int i = 0; i < R; i++) {
      int s, t;
      cin >> s >> t;
      int tmp = word[s - 1];
      word[s - 1] = word[t - 1];
      word[t - 1] = tmp;
    }
    map<int, int> bubblehist;
    bubblehist[word[0]] = 0;
    long long ans = factmodary[N - 1] * (word[0] - 1);
    for (int i = 1; i < N; i++) {
      int facttime = word[i] - 1;
      int bubblenum;
      map<int, int>::iterator it = bubblehist.lower_bound(word[i]);
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
      map<int, int>::iterator it2 = bubblehist.insert(it, p);
      for (++it2; it2 != bubblehist.end(); it2++)
        (it2->second)++;
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
