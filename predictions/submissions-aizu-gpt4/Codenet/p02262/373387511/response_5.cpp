#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int cnt;
vector<int> G;
void insertionSort(vector<int>& a, int g) {
  int n = a.size();
  for (int i = g; i < n; i++) {
    int tmp = a[i];
    int j = i - g;
    while (j >= 0 && a[j] > tmp) {
      a[j + g] = a[j];
      j -= g;
      cnt++;
    }
    a[j + g] = tmp;
  }
}
void selectionSort(vector<int>& a) {
  cnt = 0;
  for (int h = 1;;) {
    if (h > a.size())
      break;
    G.push_back(h);
    h = 3 * h + 1;
  }
  reverse(G.begin(), G.end());
  for (int g : G) {
    insertionSort(a, g);
  }
}
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  selectionSort(a);
  cout << G.size() << endl;
  for (int i = G.size() - 1; i >= 0; --i) {
    if (i != G.size() - 1) cout << " ";
    cout << G[i];
  }
  cout << endl;
  cout << cnt << endl;
  for (int i = 0; i < n; i++) {
    cout << a[i] << endl;
  }
  return 0;
}