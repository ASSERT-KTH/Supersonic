#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int N, K;
  while (cin >> N >> K, N || K) {
    vector<int> S(K);
    for (int& s : S)
      cin >> s;

    for (int i = 0; i < N; ++i) {
      for (int& s : S) {
        int B;
        cin >> B;
        s -= B;
        if (s < 0) {
          cout << "No\n";
          goto next_case;
        }
      }
    }

    cout << "Yes\n";

  next_case:
    continue;
  }

  return 0;
}