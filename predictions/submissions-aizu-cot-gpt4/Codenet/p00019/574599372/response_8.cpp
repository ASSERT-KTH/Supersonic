#include <iostream>
using namespace std;

int main() {
  long long a = 1;
  int n;
  cin >> n;
  while (n > 1) {
    a *= n--;
  }
  cout << a << '\n';
  return 0;
}