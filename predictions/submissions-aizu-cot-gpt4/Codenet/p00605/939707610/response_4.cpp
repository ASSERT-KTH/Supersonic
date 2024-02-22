#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int N, K, B, a;
  while (a = 1, cin >> N >> K, N || K) {
    vector<int> S(K);
    for (int i = K; i--;)
      cin >> S[i];
    for (int i = 0; i < N && a; ++i)
      for (int j = K; j-- && a;)
        cin >> B, S[j] -= B, a = S[j] >= 0 ? 1 : 0;
    cout << (a ? "Yes" : "No") << endl;
  }
  return 0;
}