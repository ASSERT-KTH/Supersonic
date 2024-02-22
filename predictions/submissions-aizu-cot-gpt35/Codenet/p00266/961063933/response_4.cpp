#include <iostream>
using namespace std;

const int divisor = 1000000007;

int main() {
  for (;;) {
    int N, R;
    cin >> N;
    if (N == 0)
      break;
    cin >> R;
    
    int word[N];
    for (int i = 0; i < N; i++)
      word[i] = i + 1;

    for (int i = 0; i < R; i++) {
      int s, t;
      cin >> s >> t;
      swap(word[s - 1], word[t - 1]);
    }
    
    int bubblenum[N];
    for (int i = 0; i < N; i++)
      bubblenum[i] = 0;
    
    long long ans = 0;
    long long fact = 1;
    for (int i = 0; i < N; i++) {
      int facttime = word[i] - 1;
      int count = 0;
      for (int j = 0; j < i; j++) {
        if (word[j] < word[i])
          count++;
      }
      bubblenum[i] = count;
      
      ans += (fact * facttime) % divisor;
      ans %= divisor;
      
      fact *= (i + 1);
      fact %= divisor;
    }
    
    cout << ans << "\n";
  }
  
  return 0;
}