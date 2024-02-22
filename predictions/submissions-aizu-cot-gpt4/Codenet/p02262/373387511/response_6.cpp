#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& a, int g, int& cnt) {
  int n = a.size();
  for (int i = g; i < n; i++) {
    int v = a[i];
    int j = i - g;
    while (j >= 0 && a[j] > v) {
      a[j + g] = a[j];
      j = j - g;
      cnt++;
    }
    a[j + g] = v;
  }
}

void shellSort(vector<int>& a) {
  int cnt = 0;
  int h = 1, size = 0, last;
  while (h <= a.size()) {
    if (size > 0) cout << " ";
    cout << h;
    last = h;
    h = 3 * h + 1;
    size++;
  }
  cout << endl;
  for (h = last; h > 0; h = (h - 1) / 3) {
    if (h < a.size()) insertionSort(a, h, cnt);
  }
  cout << size << endl << cnt << endl;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  shellSort(a);
  for (int i = 0; i < n; i++) {
    cout << a[i] << endl;
  }
  return 0;
}