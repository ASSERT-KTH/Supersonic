#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);  // Disable synchronization of C++ and C standard streams
  cin.tie(NULL);  // Unties cin from cout

  int n, k;
  while (cin >> n >> k) {
    if (n / 2 < k) {
      cout << "-1\n";
      continue;
    }
    vector<int> p(n + 2);  // Use a vector instead of an array
    p[0] = 0;
    for (int i = 1; i < n; i += 2) {
      p[i] = i / 2 + 1;
      p[i + 1] = n - p[i];
    }
    for (int i = 0; i < k; i++) {
      if (i != 0)
        cout << "\n";
      
      int a, b;
      for (int j = 0; j < n - 1; j++) {
        a = (p[j] + i) % n + 1;
        b = (p[j + 1] + i) % n + 1;
        cout << a << " " << b << "\n";
      }
    }
  }

  return 0;
}