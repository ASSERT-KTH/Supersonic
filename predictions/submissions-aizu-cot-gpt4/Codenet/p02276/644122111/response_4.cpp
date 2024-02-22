#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_partition_ints(const vector<int>& as, const int q, const int n) {
  for (int i = 0; i < q; ++i) {
    cout << as[i] << " ";
  }
  cout << "[" << as[q] << "] ";
  for (int i = q + 1; i < n; ++i) {
    cout << as[i] << " ";
  }
  cout << "\n";
}

int partition(vector<int>& as, const int first, const int last) {
  int less = first;
  for (int i = first; i < last; ++i) {
    if (as[i] <= as[last]) {
      swap(as[less], as[i]);
      ++less;
    }
  }
  swap(as[less], as[last]);
  return less;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> as(n);
  for (int i = 0; i < n; ++i) {
    cin >> as[i];
  }
  int q = partition(as, 0, n - 1);
  print_partition_ints(as, q, n);
}