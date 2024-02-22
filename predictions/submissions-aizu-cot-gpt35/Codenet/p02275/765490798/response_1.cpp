#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void counting_sort(vector<int>& v) {
  int n = v.size(), k = *max_element(v.begin(), v.end());
  vector<int> cnt(k + 1), tmp(v);
  cnt[0]--;
  for (int x : v)
    cnt[x]++;
  for (int i = 0; i < k; i++)
    cnt[i + 1] += cnt[i];
  for (int i = n - 1; i >= 0; i--) {
    v[cnt[tmp[i]]] = tmp[i];
    cnt[tmp[i]]--;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  cin >> n;
  vector<int> A;
  A.reserve(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    A.push_back(x);
  }
  counting_sort(A);
  cout << A[0];
  for (int i = 1; i < n; i++) {
    cout << " " << A[i];
  }
  cout << endl;
  
  return 0;
}