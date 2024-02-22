#include <iostream>
#include <vector>
using namespace std;

int insertionSort(vector<int>& a, int g) {
  int cnt = 0;
  for (int i = g; i < a.size(); i++) {
    int j = i;
    while (j - g >= 0 && a[j - g] > a[j]) {
      swap(a[j], a[j - g]);
      j -= g;
      cnt++;
    }
  }
  return cnt;
}

void shellSort(vector<int>& a) {
  int cnt = 0;
  int h = 1;
  vector<int> G;

  while(h <= a.size()) {
    G.push_back(h);
    h = 3 * h + 1;
  }

  for (int i = G.size() - 1; i >= 0; i--) {
    cnt += insertionSort(a, G[i]);
  }

  cout << G.size() << endl;
  for (int i = G.size() - 1; i >= 0; i--) {
    cout << (i != G.size() - 1 ? " " : "") << G[i];
  }
  cout << endl;
  cout << cnt << endl;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  shellSort(a);
  for (int i = 0; i < n; i++) {
    cout << a[i] << endl;
  }
  return 0;
}