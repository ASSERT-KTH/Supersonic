#include <iostream>
#include <vector>
using namespace std;
static int cnt;
static vector<int> G;
inline void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
void insertionSort(int *a, int g, const int n) {
  for (int i = g; i < n; i++) {
    int j = i;
    while (j >= g && a[j - g] > a[j]) {
      swap(a[j], a[j-g]);
      j -= g;
      cnt++;
    }
  }
}
void selectionSort(int *a, const int n) {
  cnt = 0;
  G.reserve(n/9);
  for (int h = 1; h <= n; h = 3 * h + 1)
    G.push_back(h);
  for (int i = G.size() - 1; i >= 0; i--)
    insertionSort(a, G[i], n);
}
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a)
    cin >> i;
  selectionSort(a.data(), n);
  cout << G.size() << '\n';
  for (int i = G.size() - 1; i >= 0; --i)
    cout << G[i] << (i > 0 ? " " : "\n");
  cout << cnt << '\n';
  for (const int &i : a)
    cout << i << '\n';
  return 0;
}