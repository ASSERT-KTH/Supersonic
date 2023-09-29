#include <iostream>
#include <vector>
using namespace std;
int main() {
  int N, K, B;
  bool a;
  while (cin >> N >> K, N || K) {
    vector<int> S(K);
    for (int &s : S)
      cin >> s;
    a = true;
    for (int i = 0; i < N && a; ++i)
      for (int &s : S)
        cin >> B, s -= B, a &= s >= 0;
    cout << (a ? "Yes" : "No") << endl;
  }
}