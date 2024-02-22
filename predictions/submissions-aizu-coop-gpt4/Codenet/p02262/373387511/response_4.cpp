#include <iostream>
#include <vector>
#include <algorithm>  // For using std::swap
using namespace std;
int cnt;
vector<int> G;
void insertionSort(vector<int> &a, int g, int n) {
  for (int i = g; i < n; i++) {
    int j = i, prev = j - g;
    int prev_val = a[prev];
    while (prev >= 0 && prev_val > a[j]) {
      std::swap(a[j], a[prev]);
      j = prev;
      prev -= g;
      if(prev >= 0)
        prev_val = a[prev];
      cnt++;
    }
  }
}
void shellSort(vector<int> &a, int n) {
  cnt = 0;
  for (int h = 1; h <= n; h = 3 * h + 1) {
    G.push_back(h);
  }
  for (int i = G.size() - 1; i >= 0; i--) {
    insertionSort(a, G[i], n);
  }
}
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  shellSort(a, n);
  cout << G.size() << endl;
  for (int i = G.size() - 1; i >= 0; i--) {
    cout << (i == G.size() - 1 ? "" : " ") << G[i];
  }
  cout << endl << cnt << endl;
  for (int i = 0; i < n; i++) {
    cout << a[i] << endl;
  }
  return 0;
}