#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int N, K, B;
  while (cin >> N >> K, N || K) {
    vector<int> S(K);
    for (int i = K; i--;)
      cin >> S[i];
    for (int i = 0; i < N; ++i)
      for (int j = K; j--;)
        cin >> B, S[j] -= B;
    cout << (*min_element(S.begin(), S.end()) < 0 ? "No" : "Yes") << endl;
  }
  return 0;
}