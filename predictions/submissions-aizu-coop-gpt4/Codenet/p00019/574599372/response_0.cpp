#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<long long> factorial(n + 1);
  factorial[0] = 1;
  for (int i = 1; i <= n; i++) {
    factorial[i] = factorial[i - 1] * i;
  }

  cout << factorial[n] << endl;

  return 0;
}