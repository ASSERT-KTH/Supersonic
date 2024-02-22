#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> tb, ans;

// Function to calculate cubic numbers
void calc_cubic(int N) {
  tb.resize(N+1);
  for (int i = 1; i <= N; i++)
    tb[i] = i * i * i;
}

// Binary search function to find number
int nr(int a) {
  int low = 2, high = tb.size()-1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (tb[mid] > a) 
      high = mid - 1;
    else 
      low = mid + 1;
  }
  return tb[high];
}

// Function to calculate ans
int calc(int z) {
  int z3 = z * z * z, ret = z3;
  for (int i = z; i >= 1; i--) {
    int i3 = i * i * i, j3 = nr(z3 - i3);
    ret = min(ret, z3 - i3 - j3);
  }
  return ret;
}

int main() {
  int N;
  while (cin >> N, N) {
    calc_cubic(N);
    ans.resize(N+1);
    for (int i = 1; i <= N; i++)
      ans[i] = calc(i);
    cout << ans[N] << endl;
  }
  return 0;
}