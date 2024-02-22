#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K, B;
  while (cin >> N >> K, N || K) {
    vector<int> S(K);
    for (int i = K; i--;)
      cin >> S[i];

    bool a = true;
    for (int i = 0; i < N; ++i) {
      vector<int> temp(K);
      for (int j = K; j--;)
        cin >> temp[j], S[j] -= temp[j];
      for (int j : S) {
        if (j < 0) {
          a = false;
          break;
        }
      }
    }
    cout << (a ? "Yes" : "No") << endl;
  }
  return 0;
}