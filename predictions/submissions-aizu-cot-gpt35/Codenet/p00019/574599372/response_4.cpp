#include <iostream>
using namespace std;

unsigned long long factorial(int n) {
  if (n == 0 || n == 1)
    return 1;
  else
    return n * factorial(n - 1);
}

int main() {
  int n;
  cin >> n;
  unsigned long long result = factorial(n);
  cout << result << endl;
  return 0;
}