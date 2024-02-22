#include <iostream>
#include <stack>
using namespace std;
int cnt;
stack<int> G;
void insertionSort(int *a, int g, int n) {
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
void selectionSort(int *a, int n) {
  cnt = 0;
  for (int h = 1;;) {
    if (h > n)
      break;
    G.push(h);
    h = 3 * h + 1;
  }
  while (!G.empty()) {
    insertionSort(a, G.top(), n);
    G.pop();
  }
}
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  selectionSort(a.data(), n);
  cout << G.size() << endl;
  while (!G.empty()) {
    cout << G.top() << " ";
    G.pop();
  }
  cout << endl;
  cout << cnt << endl;
  for (int i = 0; i < n; i++) {
    cout << a[i] << endl;
  }
  return 0;
}