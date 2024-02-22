#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void insertionSort(vector<int>& a, int g, int& cnt) {
  int n = a.size();
  for (int i = g; i < n; i++) {
    int j = i;
    while (j - g >= 0 && a[j - g] > a[j]) {
      swap(a[j], a[j - g]);
      j = j - g;
      cnt++;
    }
  }
}

void shellSort(vector<int>& a, vector<int>& G, int& cnt) {
  int n = a.size();
  cnt = 0;
  for (int h = 1;;) {
    if (h > n)
      break;
    G.push_back(h);
    h = 3 * h + 1;
  }
  for (int i = G.size() - 1; i >= 0; i--) {
    insertionSort(a, G[i], cnt);
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
  vector<int> G;
  G.reserve(n);  // reserve space for n elements

  shellSort(a, G, cnt);

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