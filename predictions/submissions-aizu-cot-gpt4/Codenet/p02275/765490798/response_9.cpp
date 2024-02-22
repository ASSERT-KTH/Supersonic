#include "bits/stdc++.h"
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

const int MOD = (int)(1e9 + 7);

void counting_sort(vector<int> &v) {
  int n = v.size();
  int k = v[0];
  vector<int> cnt;
  
  for (int x : v) {
    if(x > k) k = x; // find the maximum element
    if(x >= cnt.size()) cnt.resize(x + 1); // resize the count vector if necessary
    cnt[x]++;
  }

  int pos = 0;
  for(int i = 0; i <= k; i++) {
    while(cnt[i] > 0) {
      v[pos++] = i;
      cnt[i]--;
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  rep(i, 0, n) { cin >> A[i]; }

  counting_sort(A);

  int ASize = A.size();
  cout << A[0];
  rep(i, 1, ASize) { cout << " " << A[i]; }
  cout << endl;
  
  return 0;
}