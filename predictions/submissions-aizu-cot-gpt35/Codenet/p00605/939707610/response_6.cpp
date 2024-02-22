#include <iostream>
using namespace std;

int main() {
  int N, K, i, j, *S, a;
  while (cin >> N >> K, N || K) {
    S = new int[K];
    for (i = K; i--;)
      cin >> S[i];
    a = 1;
    for (i = 0; i < N; ++i) {
      for (j = 0; j < K; ++j) {
        cin >> S[j];
        S[j] -= S[j];
        if (S[j] < 0) {
          a = 0;
          break;
        }
      }
    }
    cout << (a ? "Yes" : "No") << endl;
    delete[] S;
  }
}