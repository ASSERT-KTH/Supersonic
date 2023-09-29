#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
void counting_sort(vector<int> &v) {
  int n = v.size(), k = *max_element(v.begin(), v.end());
  vector<int> cnt(k + 1), tmp(v);
  for (int x : v)
    cnt[x]++;
  for (int i = 1; i <= k; i++)
    cnt[i] += cnt[i-1];
  for (int i = n - 1; i >= 0; i--) {
    v[--cnt[tmp[i]]] = tmp[i];
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> A(n);
  rep(i, 0, n) { cin >> A[i]; }
  counting_sort(A);
  cout << A[0];
  rep(i, 1, A.size()) { cout << " " << A[i]; }
  cout << "\n";
  return 0;
}