#include <iostream>
#include <vector>
using namespace std;

void counting_sort(vector<int>& A) {
  int n = A.size();
  int k = *max_element(A.begin(), A.end());
  
  vector<int> cnt(k);
  for (int x : A)
    cnt[x - 1]++;
  
  int index = 0;
  for (int i = 0; i < k; i++) {
    while (cnt[i] > 0) {
      A[index++] = i + 1;
      cnt[i]--;
    }
  }
}

int main() {
  int n;
  cin >> n;
  
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  
  counting_sort(A);
  
  for (int i = 0; i < n; i++) {
    cout << A[i] << " ";
  }
  cout << endl;
  
  return 0;
}