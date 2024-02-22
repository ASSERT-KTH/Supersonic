#include <iostream>
#include <vector>
using namespace std;
int main() {
  int N, K;
  while (cin >> N >> K, N || K) {
    int a = 1;
    vector<int> S(K);
    for (int i = K; i--;)
      cin >> S[i];
    for (int i = 0; i < N; ++i)
      for (int j = K; j--;) {
        int B;
        cin >> B;
        S[j] -= B;
        if (S[j] < 0) a = 0;
      }
    cout << (a ? "Yes" : "No") << endl;
  }
}