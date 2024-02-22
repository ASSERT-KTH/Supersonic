#include <iostream>
using namespace std;
int main() {
  int N, K, i, j, S[1000], B, a = 1;
  while (cin >> N >> K, N || K) {
    for (i = K; i--;)
      cin >> S[i];
    for (i = 0; i < N; ++i)
      for (j = K; j--;)
        cin >> B, S[j] -= B, S[j] < 0 ? a = 0 : 0;
    cout << (a ? "Yes" : "No") << endl;
    a = 1; // Reset the flag for next iteration
  }
  return 0;
}