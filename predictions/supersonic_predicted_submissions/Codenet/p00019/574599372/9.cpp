#include <bits/stdc++.h>
using namespace std;
main() {
  int a = 1;
  int i, n;
  cin >> n;
  for (i = 2; i <= n; i++) {
    a = a * i;
  }
  cout << a << endl;
}
