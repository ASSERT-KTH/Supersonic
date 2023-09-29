#include <iostream>
#include <vector>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int N, K, B;
  while (cin >> N >> K, N || K) {
    vector<int> S(K);
    bool a = true;
    for (auto &s : S)
      cin >> s;
    while (N--) {
      for (auto &s : S) {
        cin >> B;
        if ((s -= B) < 0)
          a = false;
      }
    }
    cout << (a ? "Yes\n" : "No\n");
  }
}