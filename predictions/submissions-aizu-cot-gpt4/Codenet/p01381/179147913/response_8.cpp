#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, k;
  while (cin >> n >> k) {
    if (n / 2 < k) {
      cout << "-1\n";
      continue;
    }
    vector<int> p(n + 2);
    p[0] = 0;
    for (int i = 1; i < n; i += 2) {
      p[i] = i / 2 + 1;
      p[i + 1] = n - p[i];
    }
    for (int i = 0; i < k; i++) {
      vector<int> a(n - 1), b(n - 1);
      for (int j = 0; j < n - 1; j++) {
        a[j] = p[j] + i;
        if (a[j] >= n) a[j] -= n;
        a[j]++;
        b[j] = p[j + 1] + i;
        if (b[j] >= n) b[j] -= n;
        b[j]++;
      }
      for (int j = 0; j < n - 1; j++) {
        cout << a[j] << " " << b[j] << "\n";
      }
      if (i != k - 1) cout << "\n";
    }
  }
  return 0;
}