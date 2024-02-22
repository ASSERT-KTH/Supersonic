#include <iostream>
#include <vector>
using namespace std;

int cnt;

void insertionSort(vector<int>& a, int g, int n) {
  for (int i = g; i < n; ++i) {
    int j = i;
    while (j - g >= 0 && a[j - g] > a[j]) {
      swap(a[j], a[j - g]);
      j = j - g;
      cnt++;
    }
  }
}

vector<int> shellSort(vector<int>& a, int n) {
  cnt = 0;
  vector<int> G;
  for (int h = 1; h <= n; h = 3 * h + 1) {
    G.push_back(h);
  }
  for (int i = G.size() - 1; i >= 0; i--) {
    insertionSort(a, G[i], n);
  }
  return G;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> G = shellSort(a, n);
  cout << G.size() << endl;
  for (int i = G.size() - 1; i >= 0; i--) {
    cout << (i == G.size() - 1 ? "" : " ") << G[i];
  }
  cout << endl;
  cout << cnt << endl;
  for (int i = 0; i < n; i++) {
    cout << a[i] << endl;
  }
  return 0;
}