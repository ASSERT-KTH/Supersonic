#include <iostream>
using namespace std;

#define MAX 1000 // Assuming K will not exceed this value

int main() {
  int N, K, i, j, S[MAX], B, a;

  while (cin >> N >> K, N || K) {
    a = 1;
    for (i = 0; i < K; ++i) // Read in initial values
      cin >> S[i];
    for (i = 0; i < N; ++i) {
      for (j = 0; j < K; ++j) {
        cin >> B;
        S[j] -= B;
        if (S[j] < 0) {
          a = 0;
          break; // Break out of loop as soon as a negative number is found
        }
      }
      if (a == 0) break; // If a is 0, break out of outer loop as well
    }
    cout << (a ? "Yes" : "No") << endl;
  }

  return 0;
}