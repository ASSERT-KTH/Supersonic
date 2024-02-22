#include <iostream>
#include <vector>

void insertionSort(int *a, int g, int n) {
  for (int i = g; i < n; i++) {
    int j = i;
    int tmp = a[i];
    while (j - g >= 0 && a[j - g] > tmp) {
      a[j] = a[j - g];
      j = j - g;
    }
    a[j] = tmp;
  }
}

void selectionSort(int *a, int n) {
  std::vector<int> G;
  for (int h = 1;;) {
    if (h > n)
      break;
    G.push_back(h);
    h = 3 * h + 1;
  }
  for (int i = G.size() - 1; i >= 0; i--) {
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
  std::cout << G.size() << std::endl;
  std::cout << G[G.size() - 1];
  for (int i = G.size() - 2; i >= 0; i--) {
    std::cout << " " << G[i];
  }
  std::cout << std::endl;
  for (int i = 0; i < n; i++) {
    std::cout << a[i] << std::endl;
  }
  return 0;
}