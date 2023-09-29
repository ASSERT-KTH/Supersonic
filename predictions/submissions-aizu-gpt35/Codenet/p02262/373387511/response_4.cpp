#include <iostream>
#include <vector>
using namespace std;

int cnt;
vector<int> G;

void insertionSort(int *a, int g, int n) {
  for (int i = g - 1; i < n; i++) {
    int j = i;
    int tmp = a[i];
    while (j - g >= 0 && a[j - g] > tmp) {
      a[j] = a[j - g];
      j = j - g;
      cnt++;
    }
    a[j] = tmp;
  }
}

void selectionSort(int *a, int n) {
  cnt = 0;
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
  cin >> n;
  int *a = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  selectionSort(a, n);
  cout << G.size() << endl;
  cout << G[G.size() - 1];
  for (int i = G.size() - 2; i >= 0; i--) {
    cout << " " << G[i];
  }
  cout << endl;
  cout << cnt << endl;
  for (int i = 0; i < n; i++) {
    cout << a[i] << endl;
  }
  delete[] a;
  return 0;
}