#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& a, int g, int& cnt) {
  int n = a.size();
  for (int i = g; i < n; i++) {
    int j = i;
    while (j >= g && a[j - g] > a[j]) {
      swap(a[j], a[j - g]);
      j -= g;
      cnt++;
    }
  }
}

void selectionSort(vector<int>& a) {
  int cnt = 0;
  vector<int> G;
  for (int h = 1; h <= a.size(); h = 3 * h + 1) {
    G.push_back(h);
  }
  for (int i = G.size() - 1; i >= 0; i--) {
    insertionSort(a, G[i], cnt);
  }
  
  cout << G.size() << endl;
  for(auto it = G.rbegin(); it != G.rend(); ++it) {
    cout << (it == G.rbegin() ? "" : " ") << *it;
  }
  cout << endl << cnt << endl;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& item : a) {
    cin >> item;
  }
  selectionSort(a);
  for (const int& item : a) {
    cout << item << endl;
  }
  return 0;
}