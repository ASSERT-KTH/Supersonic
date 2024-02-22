#include <iostream>
using namespace std;
int main() {
  int N, K, i, j, S[100], B, a;
  while (a = 1, cin >> N >> K, N || K) {
    for (i = 0; i < K; ++i)
      cin >> S[i];
    for (i = 0; i < N && a; ++i)
      for (j = 0; j < K; ++j) {
        cin >> B;
        if(a) {
          S[j] -= B;
          if(S[j] < 0) {
            a = 0;
            break;
          }
        }
      }
    cout << (a ? "Yes" : "No") << endl;
  }
  return 0;
}