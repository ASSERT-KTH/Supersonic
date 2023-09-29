#include <iostream>
#include <vector>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  int N, K, B, a;
  while (a = 1, cin >> N >> K, N || K) {
    vector<int> S(K);
    for (int &s : S)
      cin >> s;
    for (int i = 0; i < N; ++i)
      for (int &s : S)
        cin >> B, s -= B, s < 0 ? a = 0 : 0;
    cout << (a ? "Yes" : "No") << '\n';
  }
}