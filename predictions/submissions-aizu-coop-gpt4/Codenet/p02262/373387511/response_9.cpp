#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int cnt;
deque<int> G;

void insertionSort(int *a, int g, int n) {
  for (int i = g; i < n; i++) {
    int j = i;
    while (j - g >= 0 && a[j - g] > a[j]) {
      swap(a[j], a[j - g]);  // Use std::swap function
      j -= g;
      cnt++;
    }
  }
}

void selectionSort(int *a, int n) {
  cnt = 0;
  for (int h = 1; h <= n; h = 3 * h + 1) {
    G.push_front(h);  // Insert at the beginning
  }
  for (int i = 0; i < G.size(); i++) {
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
  selectionSort(a, n);
  cout << G.size() << endl;
  for (int i = G.size() - 1; i >= 0; i--) {
    cout << G[i] << " ";
  }
  cout << endl;
  cout << cnt << endl;
  for (int i = 0; i < n; i++) {
    cout << a[i] << endl;
  }
  return 0;
}