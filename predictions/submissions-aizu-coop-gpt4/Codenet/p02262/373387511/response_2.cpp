#include <iostream>
#include <deque>
using namespace std;

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

void selectionSort(int *a, int n, int &cnt) {
  cnt = 0;
  deque<int> G;
  for (int h = 1; h <= n; h = 3 * h + 1) {
    G.push_front(h);
  }
  for (auto g : G) {
    insertionSort(a, g, n, cnt);
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int cnt;
  selectionSort(a.data(), n, cnt);
  cout << G.size() << endl;
  for (auto it = G.rbegin(); it != G.rend(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
  cout << cnt << endl;
  for (auto val : a) {
    cout << val << endl;
  }
  
  return 0;
}