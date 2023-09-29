#include <iostream>
#include <vector>
using namespace std;
int cnt;
vector<int> G;
void insertionSort(int *a, int g, int n) {
  for (int i = g; i < n; i++) {
    int key = a[i];
    int j = i - g;
    while (j >= 0 && a[j] > key) {
      a[j + g] = a[j];
      j = j - g;
      cnt++;
    }
    a[j + g] = key;
  }
}
void shellSort(int *a, int n) {
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
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  shellSort(a, n);
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