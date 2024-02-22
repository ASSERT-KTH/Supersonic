#include <iostream>
using namespace std;

int main() {
  int N, K, B;
  bool a;
  int S[1000];  // Assume the maximum value of K is 1000
  
  while (cin >> N >> K, N || K) {
    a = true;
    for (int i = 0; i < K; ++i)
      cin >> S[i];
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < K; ++j) {
        cin >> B;
        S[j] -= B;
        if (S[j] < 0) {
          a = false;
          break;
        }
      }
      if (!a)
        break;
    }
    cout << (a ? "Yes" : "No") << endl;
  }
  return 0;
}