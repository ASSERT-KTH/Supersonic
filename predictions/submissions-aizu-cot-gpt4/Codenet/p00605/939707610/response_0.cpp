#include <iostream>

using namespace std;

int main() {
  int N, K, i, j, *S, B;
  bool a = true;
  
  while (cin >> N >> K, N || K) {
    S = new int[K];
    for (i = K; i--;)
      cin >> S[i];
    for (i = 0; i < N; ++i)
      for (j = K; j--;)
        cin >> B, S[j] -= B, if(S[j] < 0) a = false;
    cout << (a ? "Yes" : "No") << endl;
    delete[] S;
  }
}