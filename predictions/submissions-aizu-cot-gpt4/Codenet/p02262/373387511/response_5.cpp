#include <iostream>
#include <vector>
using namespace std;

void insertionSort(int *a, int g, int n, int &cnt) {
  for (int i = g - 1; i < n; i++) {
    int j = i;
    while (j - g >= 0 && a[j - g] > a[j]) {
      swap(a[j], a[j - g]);
      j = j - g;
      cnt++;
    }
  }
}

void selectionSort(int *a, int n, vector<int> &G, int &cnt) {
  cnt = 0;
  for (int h = 1;;) {
    if (h > n)
      break;
    G.push_back(h);
    h = 3 * h + 1;
  }
  for (int i = G.size() - 1; i >= 0; i--) {
    insertionSort(a, G[i], n, cnt);
  }
}

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> G;
  G.reserve(n);
  int cnt;
  selectionSort(a, n, G, cnt);
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
  return 0;
}