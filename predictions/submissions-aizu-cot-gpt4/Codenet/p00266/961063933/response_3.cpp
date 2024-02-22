#include <iostream>
#include <vector>
using namespace std;

const int divisor = 1000000007;

int main() {
  ios_base::sync_with_stdio(false);
  vector<long long> factmodary(100001);
  
  for (int i = 1; i <= 100000; i++) {
    factmodary[i] = (factmodary[i-1] * i) % divisor;
  }
  
  vector<int> word(100000, 0);
  
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
    
    vector<int> bubblehist(N+1, 0);
    long long ans = (factmodary[N - 1] * (word[0] - 1)) % divisor;
    
    for (int i = 1; i < N; i++) {
      int facttime = word[i] - 1;
      int bubblenum = bubblehist[word[i]];
      bubblehist[word[i]] = bubblenum + 1;
      facttime -= bubblenum;
      ans = (ans + (factmodary[N - (i + 1)] * facttime) % divisor) % divisor;
    }
    cout << ans << "\n";
  }
  
  return 0;
}