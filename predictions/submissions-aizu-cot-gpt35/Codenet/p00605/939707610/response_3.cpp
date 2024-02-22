#include <iostream>
using namespace std;

int main() {
  int N, K, i, j, *S, B, a;
  while (a = 1, cin >> N >> K, N || K) {
    S = new int[K];
    for (i = K; i--;)
      cin >> S[i];

    for (i = 0; i < N; ++i) {
      for (j = K; j--;) {
        cin >> B;
        S[j] -= B;
        if (S[j] < 0) {
          a = 0;
          break;  // Break out of the inner loop if negative value encountered
        }
      }
      if (!a) {
        // Break out of the outer loop if negative value encountered
        break;
      }
    }

    cout << (a ? "Yes" : "No") << endl;

    delete[] S; // Free the dynamically allocated memory
  }
}