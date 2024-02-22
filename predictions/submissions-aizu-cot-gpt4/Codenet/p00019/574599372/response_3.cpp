#include <iostream>
using namespace std;
int main() {
  long long factorial = 1;
  int n;
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    factorial *= i;
  }
  cout << factorial << endl;
  return 0;
}