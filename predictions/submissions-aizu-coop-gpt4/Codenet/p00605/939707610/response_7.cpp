#include <iostream>
using namespace std;

int main() {
  int N, K, i, j, B, a;
  int S[100];  // Assume the maximum value of K is 100

  while (true) {
    a = 1;
    cin >> N >> K;

    if (N == 0 && K == 0)
      break;

    for (i = K; i--;)
      cin >> S[i];

    for (i = 0; i < N; ++i) {
      for (j = K; j--;) {
        cin >> B;
        S[j] -= B;

        if (S[j] < 0) {
          a = 0;
          break;
        }
      }
      
      // Skip remaining iterations if a is 0
      if (a == 0)
        break;
    }

    cout << (a ? "Yes" : "No") << endl;
  }

  return 0;
}