#include <iostream>
using namespace std;
int main() {
  int N, K, i, j, *S, B, a;
  while (cin >> N >> K, N || K) {
    S = new int[K];
    for (i = K; i--;)
      cin >> S[i];
    for (i = 0; i < N; ++i)
      for (j = K; j--;)
        cin >> B, S[j] -= B;
    cout << (a ? "Yes" : "No") << endl;
  }
}
