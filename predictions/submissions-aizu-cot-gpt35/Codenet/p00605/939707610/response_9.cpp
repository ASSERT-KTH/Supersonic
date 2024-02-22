#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
  int N, K, i, j, S[100], B;
  while (cin >> N >> K, N || K) {
    for (i = K; i--;)
      cin >> S[i];
    for (i = 0; i < N; ++i) {
      for (j = K; j--;) {
        cin >> B;
        S[j] -= B;
        if (S[j] < 0) {
          cout << "No" << endl;
          break;
        }
      }
      if (j < 0) {
        cout << "Yes" << endl;
      }
    }
  }
}