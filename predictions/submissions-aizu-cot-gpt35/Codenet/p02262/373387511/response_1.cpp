#include <iostream>
#include <vector>

void insertionSort(int* a, int g, int n) {
  for (int i = g - 1; i < n; i++) {
    int j = i;
    while (j - g >= 0 && a[j - g] > a[j]) {
      std::swap(a[j], a[j - g]);
      j = j - g;
    }
  }
}

void selectionSort(int* a, int n) {
  int cnt = 0;
  static const int G[] = {1, 4, 13, 40, 121, 364, 1093, 3280, 9841, 29524, 88573, 265720, 797161, 2391484, 7174453, 21523360};
  int numG = sizeof(G) / sizeof(G[0]);

  for (int i = numG - 1; i >= 0; i--) {
    insertionSort(a, G[i], n);
  }
}

int main() {
  int n;
  std::cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  selectionSort(a, n);

  std::cout << sizeof(G) / sizeof(G[0]) << std::endl;
  std::cout << G[numG - 1];
  for (int i = numG - 2; i >= 0; i--) {
    std::cout << " " << G[i];
  }
  std::cout << std::endl;

  std::cout << cnt << std::endl;
  for (int i = 0; i < n; i++) {
    std::cout << a[i] << std::endl;
  }

  return 0;
}