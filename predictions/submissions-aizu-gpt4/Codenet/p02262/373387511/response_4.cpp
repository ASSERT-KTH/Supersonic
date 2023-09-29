#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cnt;
vector<int> G;

void shellSort(int *a, int n) {
  cnt = 0;
  
  // Generate the sequence
  for (int h = 1; h <= n; h = 3 * h + 1) {
    G.push_back(h);
  }
  
  // Sort using the sequence
  for (auto it = G.rbegin(); it != G.rend(); ++it) {
    int g = *it;
    
    for (int i = g; i < n; ++i) {
      int temp = a[i];
      int j;
      
      for (j = i; j >= g && a[j - g] > temp; j -= g) {
        a[j] = a[j - g];
        ++cnt;
      }
      
      a[j] = temp;
    }
  }
}

int main() {
  int n;
  
  cin >> n;
  
  int *a = new int[n];
  
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  
  shellSort(a, n);
  
  cout << G.size() << "\n";
  
  for (auto it = G.rbegin(); it != G.rend(); ++it) {
    cout << *it << " ";
  }
  
  cout << "\n";
  
  cout << cnt << "\n";
  
  for (int i = 0; i < n; ++i) {
    cout << a[i] << "\n";
  }
  
  delete[] a;
  
  return 0;
}