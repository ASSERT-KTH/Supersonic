#include <iostream>
#define MAX_K 10000 // assuming maximum K value is 10000
using namespace std;

int main() {
  int N, K, i, j, S[MAX_K], B, a;
  while (cin >> N >> K, N || K) {
    for (i = K; i--;)
      cin >> S[i];
    a = 1;
    for (i = 0; i < N && a; ++i)
      for (j = K; j-- && a;) {
        cin >> B;
        S[j] -= B;
        if (S[j] < 0)
          a = 0;
      }
    cout << (a ? "Yes" : "No") << endl;
  }
  return 0;
}