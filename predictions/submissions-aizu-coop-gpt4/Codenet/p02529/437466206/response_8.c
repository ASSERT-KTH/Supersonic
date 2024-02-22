#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  int n, q, t, C = 0;
  unordered_set<int> T;
  cin >> n;
  int S[n];
  for (int i = 0; i < n; i++) {
    cin >> S[i];
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> t;
    T.insert(t);
  }
  for (int i = 0; i < n; i++) {
    if (T.find(S[i]) != T.end()) {
      C++;
    }
  }
  cout << C << endl;
  return 0;
}