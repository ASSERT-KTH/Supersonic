#include <iostream>
using namespace std;

void shellSort(int *a, int n) {
  int gaps[] = { 121, 40, 13, 4, 1 }; // Predefined gap sequence
  int numGaps = sizeof(gaps) / sizeof(gaps[0]);

  for (int gapIndex = 0; gapIndex < numGaps; gapIndex++) {
    int gap = gaps[gapIndex];

    for (int i = gap; i < n; i++) {
      int temp = a[i];
      int j;
      for (j = i; j >= gap && a[j - gap] > temp; j -= gap) {
        a[j] = a[j - gap];
      }
      a[j] = temp;
    }
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

  cout << "5" << endl; // Number of gaps in the sequence
  cout << "121 40 13 4 1" << endl; // Gap sequence

  cout << (n - 1) << endl; // Number of comparisons
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;

  return 0;
}