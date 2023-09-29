#include <iostream>
#include <vector>
using namespace std;
int cnt;
vector<int> G;
void insertionSort(int *a, int g, int n) {
  for (int i = g; i < n; i++) {
    int v = a[i], j = i - g;
    while (j >= 0 && a[j] > v) {
      a[j + g] = a[j];
      j -= g, cnt++;
    }
    a[j + g] = v;
  }
}
void shellSort(int *a, int n) {
  cnt = 0;
  for (int h = 1; h <= n; h = 3 * h + 1) G.push_back(h);
  for (int i = G.size() - 1; i >= 0; i--) insertionSort(a, G[i], n);
}
int main() {
  int n; cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  shellSort(a, n);
  cout << G.size() << endl;
  for (int i = G.size() - 1; i >= 0; i--) cout << G[i] << " ";
  cout << endl << cnt << endl;
  for (int i = 0; i < n; i++) cout << a[i] << endl;
  return 0;
}