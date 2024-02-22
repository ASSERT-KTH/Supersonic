#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& a, int g, int n, int& cnt) {
  for (int i = g; i < n; i++) {
    int key = a[i];
    int j = i - g;
    while (j >= 0 && a[j] > key) {
      a[j + g] = a[j];
      j = j - g;
      cnt++;
    }
    a[j + g] = key;
  }
}

void shellSort(std::vector<int>& a) {
  int n = a.size();
  int cnt = 0;
  
  for (int gap = n / 2; gap > 0; gap /= 2) {
    insertionSort(a, gap, n, cnt);
  }

  std::cout << cnt << std::endl;

  for (int i = 0; i < n; i++) {
    std::cout << a[i] << std::endl;
  }
}

int main() {
  int n;
  std::cin >> n;
  
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  
  shellSort(a);
  
  return 0;
}