#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long a = 1, temp;
  int i, n;
  cin >> n;
  for (i = 2; i <= n; ++i) {
    temp = a * i;
    a = temp;
  }
  cout << a << endl;
  return 0;
}