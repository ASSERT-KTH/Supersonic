#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  long long a = 1;
  int n;
  cin >> n;
  for (auto i = 2; i <= n; ++i) {
    a = a * i;
  }
  cout << a << '\n';
  return 0;
}