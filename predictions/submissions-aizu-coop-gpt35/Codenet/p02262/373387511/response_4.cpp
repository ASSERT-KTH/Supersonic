#include <iostream>

void shellSort(int *a, int n) {
  int cnt = 0;

  // Compute the gap sequence
  int h = 1;
  while (h <= n / 3) {
    h = 3 * h + 1;
  }

  while (h >= 1) {
    // Perform insertion sort with gap h
    for (int i = h; i < n; i++) {
      int j = i;
      while (j >= h && a[j - h] > a[j]) {
        // Swap a[j] and a[j - h]
        int tmp = a[j];
        a[j] = a[j - h];
        a[j - h] = tmp;
        j = j - h;
        cnt++;
      }
    }
    h = h / 3;
  }

  std::cout << cnt << std::endl;
}

int main() {
  int n;
  std::cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  shellSort(a, n);

  for (int i = 0; i < n; i++) {
    std::cout << a[i] << std::endl;
  }
  return 0;
}