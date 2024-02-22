#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void counting_sort(vector<int> &v) {
  int n = v.size(), k = *max_element(v.begin(), v.end());
  vector<int> cnt(k + 1, 0);
  
  for (int x : v)
    cnt[x]++;
    
  for (int i = 0; i < k; i++)
    cnt[i + 1] += cnt[i];
    
  vector<int> sorted(n);
  for (int i = n - 1; i >= 0; i--) {
    sorted[cnt[v[i]] - 1] = v[i];
    cnt[v[i]]--;
  }
  v = sorted;
}

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) { cin >> A[i]; }
  counting_sort(A);
  for (int i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << A[i];
  }
  cout << "\n";
  return 0;
}