#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  int n, q, t, C = 0;
  unordered_set<int> S;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    S.insert(t);
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> t;
    if (S.find(t) != S.end()) {
      C++;
    }
  }
  cout << C << endl;
  return 0;
}