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

void shellSort(int *a, int n) {
  cnt = 0;
  int h = 1;
  while (h <= n / 3)
    h = h * 3 + 1;

  while (h > 0) {
    G.push_back(h);
    for (int i = h; i < n; i++) {
      int tmp = a[i];
      int j = i;
      while (j >= h && a[j - h] > tmp) {
        a[j] = a[j - h];
        j -= h;
        cnt++;
      }
      a[j] = tmp;
    }
    h = (h - 1) / 3;
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