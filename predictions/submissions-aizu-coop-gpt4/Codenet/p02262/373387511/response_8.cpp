#include <iostream>
using namespace std;
int cnt;
int G[100];
void insertionSort(int *a, int g, int n) {
  for (int i = g; i < n; i++) {
    int key = a[i];
    int j = i - g;
    while (j >= 0 && a[j] > key) {
      a[j + g] = a[j];
      j -= g;
      cnt++;
    }
    a[j + g] = key;
  }
}
void shellSort(int *a, int n) {
  cnt = 0;
  int h, i;
  for (h = 1, i = 0;; i++) {
    if (h > n)
      break;
    G[i] = h;
    h = 3 * h + 1;
  }
  int m = i;
  for (i = m - 1; i >= 0; i--) {
    insertionSort(a, G[i], n);
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
  cout << cnt << endl;
  for (int i = 0; i < n; i++) {
    cout << a[i] << endl;
  }
  return 0;
}