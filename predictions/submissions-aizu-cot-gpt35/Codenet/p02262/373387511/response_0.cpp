#include <iostream>
#include <vector>
#include <iterator>
using std::cout;
using std::cin;
using std::endl;
using std::ostream_iterator;
using std::vector;

int cnt;
int* G;

void insertionSort(int *a, int g, int n) {
  for (int i = g - 1; i < n; i++) {
    int j = i;
    while (j - g >= 0 && a[j - g] > a[j]) {
      std::swap(a[j], a[j - g]);
      j = j - g;
      cnt++;
    }
  }
}

void selectionSort(int *a, int n) {
  cnt = 0;
  vector<int> tmpG;
  for (int h = 1;;) {
    if (h > n)
      break;
    tmpG.push_back(h);
    h = 3 * h + 1;
  }
  G = new int[tmpG.size()];
  for (int i = 0; i < tmpG.size(); i++) {
    G[i] = tmpG[i];
  }
  for (int i = tmpG.size() - 1; i >= 0; i--) {
    insertionSort(a, G[i], n);
  }
}

int main() {
  int n;
  cin >> n;
  int* a = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  selectionSort(a, n);
  int G_size = tmpG.size();
  cout << G_size << endl;
  copy(G, G + G_size, ostream_iterator<int>(cout, " "));
  cout << endl;
  cout << cnt << endl;
  copy(a, a + n, ostream_iterator<int>(cout, "\n"));
  delete[] G;
  delete[] a;
  return 0;
}