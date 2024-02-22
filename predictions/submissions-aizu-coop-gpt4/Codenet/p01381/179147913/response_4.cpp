#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); // boost performance when using cin and cout
  int n, k;
  vector<int> p; // dynamic array to avoid unnecessary initializations
  while (cin >> n >> k) {
    if (n / 2 < k) {
      cout << "-1\n";
      continue;
    }
    if (p.size() < n + 2) // resize the array only if necessary
      p.resize(n + 2);
    for (int i = 1; i < n; i += 2) {
      p[i] = i / 2 + 1;
      p[i + 1] = n - p[i];
    }
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < n - 1; j++) {
        int a = (p[j] + i) % n + 1;
        int b = (p[j + 1] + i) % n + 1;
        if (j != 0)
          cout << '\n'; // use '\n' instead of endl to avoid unnecessary buffer flushes
        cout << a << ' ' << b;
      }
      cout << '\n'; // print a newline at the end of each block
    }
  }
  return 0;
}