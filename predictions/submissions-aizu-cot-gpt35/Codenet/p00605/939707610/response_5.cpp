#include <iostream>
using namespace std;

const int MAX_K = 1000; // Maximum value of K

int main() {
  int N, K, i, j, S[MAX_K], B, a;
  while (a = 1, cin >> N >> K, N || K) {
    for (i = K; i--;)
      cin >> S[i];
    for (i = 0; i < N; ++i) {
      for (j = 0; j < K; ++j) {
        cin >> B;
        S[j] -= B;
        if (S[j] < 0) {
          a = 0;
          break;
        }
      }
    }
    cout << (a ? "Yes" : "No") << endl;
  }
}