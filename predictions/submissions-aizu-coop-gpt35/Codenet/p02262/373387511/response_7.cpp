#include <iostream>
#include <vector>
using namespace std;

void quickSort(int *a, int low, int high, int& cnt) {
  if (low < high) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
      if (a[j] < pivot) {
        i++;
        swap(a[i], a[j]);
        cnt++;
      }
    }
    swap(a[i + 1], a[high]);
    cnt++;
    int partitionIndex = i + 1;
    quickSort(a, low, partitionIndex - 1, cnt);
    quickSort(a, partitionIndex + 1, high, cnt);
  }
}

void selectionSort(int *a, int n, int& cnt) {
  int h = 1;
  while (h <= n) {
    h = 3 * h + 1;
  }

  int* G = new int[h];
  int index = 0;
  while (h >= 1) {
    G[index++] = h;
    h = (h - 1) / 3;
  }

  for (int i = index - 1; i >= 0; i--) {
    for (int j = G[i]; j < n; j++) {
      int temp = a[j];
      int k = j;
      while (k >= G[i] && a[k - G[i]] > temp) {
        a[k] = a[k - G[i]];
        k -= G[i];
        cnt++;
      }
      a[k] = temp;
    }
  }
  delete[] G;
}

int main() {
  int n;
  cin >> n;
  int* a = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  
  int cnt = 0;
  quickSort(a, 0, n - 1, cnt);
  cout << cnt << endl;

  cnt = 0;
  selectionSort(a, n, cnt);

  cout << n << endl;
  cout << a[0];
  for (int i = 1; i < n; i++) {
    cout << " " << a[i];
  }
  cout << endl;
  cout << cnt << endl;

  delete[] a;
  return 0;
}