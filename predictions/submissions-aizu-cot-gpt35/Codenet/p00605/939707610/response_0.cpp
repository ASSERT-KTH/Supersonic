#include <iostream>
using namespace std;
int main() {
  int N, K, i, j, *S, B;
  bool result;
  while (cin >> N >> K, N) {
    S = new int[K];
    for (i = K; i--;)
      cin >> S[i];
    result = true;
    for (i = 0; i < N; ++i)
      for (j = K; j--;)
        cin >> B, S[j] -= B, result = result && S[j] >= 0;
    cout << (result ? "Yes" : "No") << endl;
    delete[] S;
  }
}