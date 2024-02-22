#include <iostream>
using namespace std;

int main() {
  int n, k;
  while (cin >> n >> k) {
    if (n / 2 < k) {
      cout << "-1\n";
      continue;
    }
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < n - 1; j++) {
        int a = ((j / 2 + 1 + i) % n) + 1;
        int b = ((n - (j / 2 + 1) + i) % n) + 1;
        cout << a << " " << b << "\n";
      }
      if (i != k - 1)
        cout << "\n";
    }
  }
  return 0;
}