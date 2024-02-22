#include <iostream>
#include <vector>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(c) begin(c), end(c)

void counting_sort(vector<int>& v) {
  int n = v.size(), k = v[0];
  for (int x : v)
    k = max(k, x);
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
  int n;
  cin >> n;
  vector<int> A(n);
  rep(i, 0, n) { cin >> A[i]; }
  counting_sort(A);
  cout << A[0];
  rep(i, 1, A.size()) { cout << " " << A[i]; }
  cout << endl;
  return 0;
}