#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> A;
  int f;

  for (int i; cin >> i;) {
    A.push_back(i);
  }
  sort(A.begin(), A.end());

  for (auto i = A.begin(); i != A.end(); ++i) {
    cout << (f ? " " : "") << *i;
    f = 1;
  }
  cout << "\n";
}