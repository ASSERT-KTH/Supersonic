#include <iostream>
using namespace std;

int main() {
  int N, K, i, j, S[K], B, a;
  while (a = 1, cin >> N >> K, N || K) {
    for (i = K; i--;) {
      cin >> S[i];
    }
    for (i = 0; i < N; ++i) {
      int sum = 0;
      for (j = K - 1; j >= 0; j--) {
        cin >> B;
        sum += B;
      }
      for (j = K - 1; j >= 0; j--) {
        S[j] -= sum;
        if (S[j] < 0) {
          a = 0;
          break;
        }
      }
    }
    cout << (a ? "Yes" : "No") << endl;
  }
}