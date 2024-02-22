#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K, i, j, B;
  bool a;
  while (a = true, cin >> N >> K, N || K) {
    vector<int> S(K); // Use std::vector instead of dynamic memory allocation

    for (i = 0; i < K; ++i) // Use a range-based for loop to read values into S
      cin >> S[i];

    for (i = 0; i < N; ++i) {
      for (j = 0; j < K; ++j) {
        cin >> B;
        S[j] -= B;
      }

      // Check if any value in S is negative
      for (j = 0; j < K; ++j) {
        if (S[j] < 0) {
          a = false;
          break;
        }
      }
    }

    cout << (a ? "Yes" : "No") << endl;
  }

  return 0;
}