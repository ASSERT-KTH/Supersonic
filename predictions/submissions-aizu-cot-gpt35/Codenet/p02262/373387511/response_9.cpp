#include <iostream>
using namespace std;

void shellSort(int *a, int n) {
  int h = 1;
  while (h < n) {
    h = 3 * h + 1;
  }
  h = (h - 1) / 3;

  while (h > 0) {
    for (int i = h; i < n; i++) {
      int j = i;
      while (j >= h && a[j - h] > a[j]) {
        // Swap elements using XOR swap algorithm
        a[j] ^= a[j - h];
        a[j - h] ^= a[j];
        a[j] ^= a[j - h];
        j -= h;
      }
    }
    h = (h - 1) / 3;
  }
}

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  shellSort(a, n);

  cout << n << endl;
  for (int i = 0; i < n; i++) {
    cout << a[i] << endl;
  }

  return 0;
}