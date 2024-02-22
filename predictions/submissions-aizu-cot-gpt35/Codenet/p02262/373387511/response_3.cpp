#include <iostream>
#include <vector>
using namespace std;

void insertionSort(int *a, int g, int n) {
  for (int i = g; i < n; i++) {
    for (int j = i; j >= g && a[j - g] > a[j]; j -= g) {
      int tmp = a[j];
      a[j] = a[j - g];
      a[j - g] = tmp;
    }
  }
}

void selectionSort(int *a, int n) {
  int cnt = 0;
  int h = 1;
  while (h <= n) {
    h = 3 * h + 1;
  }
  h = (h - 1) / 3;
  
  while (h > 0) {
    insertionSort(a, h, n);
    h = (h - 1) / 3;
  }
  
  cout << cnt << endl;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  selectionSort(a.data(), n);
  for (int i = 0; i < n; i++) {
    cout << a[i] << endl;
  }
  return 0;
}