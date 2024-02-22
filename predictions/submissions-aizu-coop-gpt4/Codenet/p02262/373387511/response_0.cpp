#include <iostream>
#include <algorithm>  // for std::swap
using namespace std;

int cnt;
int* G;

void insertionSort(int* a, int g, int n) {
  for (int i = g - 1; i < n; i++) {
    int j = i;
    while (j - g >= 0 && a[j - g] > a[j]) {
      std::swap(a[j], a[j - g]); // Optimized swapping
      j = j - g;
      cnt++;
    }
  }
}

void selectionSort(int* a, int n) {
  cnt = 0;
  // Calculate size of G
  int size = 0;
  for (int h = 1; h <= n; h = 3 * h + 1)
    size++;

  // Allocate memory for G
  G = new int[size];
  
  int index = 0;
  for (int h = 1;; h = 3 * h + 1) {
    if (h > n)
      break;
    G[index++] = h;
  }

  for (int i = size - 1; i >= 0; i--) {
    insertionSort(a, G[i], n);
  }
}

int main() {
  int n;
  cin >> n;
  int* a = new int[n];  // Dynamic allocation
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  selectionSort(a, n);
  cout << G[G.size() - 1];
  for (int i = G.size() - 2; i >= 0; i--) {
    cout << " " << G[i];
  }
  cout << endl;
  cout << cnt << endl;
  for (int i = 0; i < n; i++) {
    cout << a[i] << endl;
  }
  
  // Free the allocated memory
  delete[] a;
  delete[] G;
  
  return 0;
}