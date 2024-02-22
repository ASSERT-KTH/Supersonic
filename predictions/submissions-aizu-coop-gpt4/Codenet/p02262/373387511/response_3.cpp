#include <iostream>
#include <algorithm> // for std::swap
using namespace std;

void insertionSort(int *a, int g, int n, int &cnt) {
  for (int i = g; i < n; ++i) {
    for (int j = i; j >= g && a[j - g] > a[j]; j -= g) {
      swap(a[j], a[j - g]);
      ++cnt;
    }
  }
}

void shellSort(int *a, int n) {
  int cnt = 0;
  int G[100]; // Assuming the gap sequence will not exceed 100
  int h = 1, size = 0;

  // Generating the gap sequence
  while (h <= n) {
    G[size++] = h;
    h = 3 * h + 1;
  }

  // Performing the shell sort
  for (int i = size - 1; i >= 0; --i) {
    insertionSort(a, G[i], n, cnt);
  }

  // Printing the results
  cout << size << endl;
  for (int i = size - 1; i >= 0; --i) {
    if (i != size - 1)
      cout << " ";
    cout << G[i];
  }
  cout << endl << cnt << endl;
  for (int i = 0; i < n; ++i) {
    cout << a[i] << endl;
  }
}

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  shellSort(a, n);
  return 0;
}