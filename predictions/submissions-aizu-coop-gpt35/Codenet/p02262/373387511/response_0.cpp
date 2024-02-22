#include <iostream>
using namespace std;

void insertionSort(int* a, int g, int n) {
  int numSwaps = 0; // Rename cnt to numSwaps for clarity

  for (int i = g; i < n; i++) { // Start i from g instead of g-1
    int key = a[i]; // Store the element to be moved
    int j = i;

    while (j >= g && a[j - g] > key) { // Use j >= g instead of j-g >= 0
      a[j] = a[j - g]; // Shift elements instead of swapping
      j -= g;
      numSwaps += 1;
    }

    a[j] = key; // Place the element in its correct position
  }
}

void shellSort(int* a, int n) {
  int numSwaps = 0;

  for (int gap = n / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; i++) {
      int key = a[i];
      int j = i;

      while (j >= gap && a[j - gap] > key) {
        a[j] = a[j - gap];
        j -= gap;
        numSwaps += 1;
      }

      a[j] = key;
    }
  }

  cout << numSwaps << endl;
}

int main() {
  int n;
  cin >> n;

  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  shellSort(a, n);

  for (int i = 0; i < n; i++) {
    cout << a[i] << endl;
  }

  return 0;
}