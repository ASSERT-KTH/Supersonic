#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void counting_sort(vector<int> &v) {
  int n = v.size(), k = *max_element(v.begin(), v.end());
  vector<int> cnt(k + 1);
  cnt[0]--;
  for (int x : v)
    cnt[x]++;
  for (int i = 0; i < k; i++)
    cnt[i + 1] += cnt[i];
  for (int i = n - 1; i >= 0; i--) {
    v[cnt[v[i]]] = v[i];
    cnt[v[i]]--;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) { cin >> A[i]; }
  counting_sort(A);
  cout << A[0];
  int size = A.size();
  for (int i = 1; i < size; i++) { cout << " " << A[i]; }
  cout << "\n";
  return 0;
}