#include <iostream>

void insertionSort(int& a, int g, int n) {
  for (int i = g - 1; i < n; i++) {
    int j = i;
    while (j - g >= 0 && a[j - g] > a[j]) {
      int tmp = a[j];
      a[j] = a[j - g];
      a[j - g] = tmp;
      j = j - g;
    }
  }
}

void selectionSort(int& a, int n) {
  int cnt = 0;
  for (int h = 1;;) {
    if (h > n)
      break;
    h = 3 * h + 1;
  }
  for (int i = h / 3; i >= 1; i = i / 3) {
    insertionSort(a, i, n);
  }
}

int main() {
  int n;
  std::cin >> n;
  int a[n];
  for (int& elem : a) {
    std::cin >> elem;
  }
  selectionSort(a, n);
  std::cout << n << std::endl;
  for (int i = n - 1; i >= 0; i--) {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}