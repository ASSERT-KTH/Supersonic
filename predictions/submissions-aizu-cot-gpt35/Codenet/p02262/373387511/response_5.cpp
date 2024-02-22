#include <iostream>
#include <vector>

void insertionSort(int* a, int g, int n) {
  for (int i = g; i < n; i++) {
    int j = i;
    int temp = a[i];
    while (j - g >= 0 && a[j - g] > temp) {
      a[j] = a[j - g];
      j = j - g;
    }
    a[j] = temp;
  }
}

void selectionSort(int* a, int n) {
  int cnt = 0;
  std::vector<int> G;
  int h = 1;
  while (h <= n) {
    G.push_back(h);
    h = (h * 3) + 1;
  }
  for (int i = G.size() - 1; i >= 0; i--) {
    insertionSort(a, G[i], n);
  }
}

int main() {
  int n;
  std::cin >> n;
  int* a = new int[n];
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
  std::cout << cnt << std::endl;
  delete[] a;
  return 0;
}
