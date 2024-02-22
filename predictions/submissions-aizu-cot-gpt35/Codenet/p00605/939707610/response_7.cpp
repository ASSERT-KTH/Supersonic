#include <iostream>

int main() {
  int N, K, i, j, S[10], B;
  bool possible;

  while (cin >> N >> K, N || K) {
    for (i = 0; i < K; ++i)
      cin >> S[i];

    possible = true;
    for (i = 0; i < N; ++i) {
      for (j = 0; j < K; ++j) {
        cin >> B;
        S[j] -= B;
        if (S[j] < 0) {
          possible = false;
        }
      }
    }

    if (possible) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}