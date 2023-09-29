#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  long long a = 1;
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    a *= i;
  }
  cout << a << endl;
  return 0;
}