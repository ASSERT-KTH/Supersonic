#include <iostream>
#include <vector>
using namespace std;

vector<int> G;

void insertionSort(int *a, int g, int n, int &cnt) {
  for (int i = g; i < n; i++) {
    int j = i;
    while (j - g >= 0 && a[j - g] > a[j]) {
      swap(a[j], a[j - g]);
      j = j - g;
      cnt++;
    }
  }
}

void shellSort(int *a, int n, int &cnt) {
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

  int cnt;
  shellSort(a, n, cnt);

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