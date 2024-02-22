#include <iostream>
using namespace std;
int main() {
  int n, k;
  while (true) {
    cin >> n >> k;
    if (n == 0 || k == 0) {
      break;
    }
    if (n / 2 < k) {
      cout << "-1" << endl;
      continue;
    }
    int p[n];
    p[0] = 0;
    for (int i = 1; i < n; i += 2) {
      p[i] = i / 2 + 1;
      p[i + 1] = n - p[i];
    }
    for (int i = 0; i < k; i++) {
      if (i != 0) {
        cout << endl;
      }
      for (int j = 0; j < n - 1; j++) {
        int a = (p[j] + i) % n + 1;
        int b = (p[j + 1] + i) % n + 1;
        cout << a << " " << b << endl;
      }
    }
  }
}