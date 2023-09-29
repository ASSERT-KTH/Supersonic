#include <iostream>
#include <vector>
using namespace std;

void counting_sort(vector<int> &v) {
  int n = v.size(), k = *max_element(v.begin(), v.end()) + 1;
  vector<int> cnt(k), tmp(n);
  for (int x : v)
    cnt[x]++;
  for (int i = 1; i < k; i++)
    cnt[i] += cnt[i-1];
  for (int i = n - 1; i >= 0; i--) {
    tmp[--cnt[v[i]]] = v[i];
  }
  v = tmp;
}

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for(int i=0; i<n; i++) {
    cin >> A[i];
  }
  counting_sort(A);
  cout << A[0];
  for(int i=1; i<n; i++) {
    cout << " " << A[i];
  }
  cout << endl;
  return 0;
}