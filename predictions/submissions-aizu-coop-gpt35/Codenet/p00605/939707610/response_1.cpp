#include <iostream>
using namespace std;

int main() {
  #pragma GCC optimize("O3") // Enable aggressive compiler optimization

  int N, K, i, j, S[100], B, a; // Use fixed-size array for S
  while (a = 1, cin >> N >> K, N || K) {
    for (i = K; i--;)
      cin >> S[i];
    for (i = 0; i < N; ++i) {
      for (j = K; j--;) {
        cin >> B;
        S[j] -= B;
        if (S[j] < 0) { // Check if S[j] becomes negative
          a = 0;
          break; // Break out of the inner loop
        }
      }
      if (a == 0) // Check if any element of S became negative
        break; // Break out of the outer loop
    }
    cout << (a ? "Yes" : "No") << endl;
  }
}