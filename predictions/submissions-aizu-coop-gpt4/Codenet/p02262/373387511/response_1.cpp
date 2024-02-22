#include <iostream>
#include <stack>
using namespace std;

void insertionSort(int *a, int &cnt, int g, int n) {
  for (int i = g; i < n; i++) {
    int j = i;
    while (j >= g && a[j - g] > a[j]) {
      swap(a[j], a[j - g]);
      j = j - g;
      cnt++;
    }
  }
}

void shellSort(int *a, int n) {
  int cnt = 0;
  stack<int> G;
  for (int h = 1; h <= n; h = 3 * h + 1) {
    G.push(h);
  }
  while (!G.empty()) {
    int g = G.top();
    G.pop();
    insertionSort(a, cnt, g, n);
  }
  cout << cnt << endl;
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