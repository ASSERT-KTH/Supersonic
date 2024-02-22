#include <cstdio>
#include <iostream>
using namespace std;

int start = 0;

int check(int N[], int n, int k, int w) {
  int i = start;
  for (int j = 0; j < k; ++j) {
    int s = 0;
    while (s + N[i] <= w) {
      s += N[i];
      ++i;
      if (i == n)
        return n;
    }
  }
  return i;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int MAX_W = 1000000000;
  int n, k;
  scanf("%d %d", &n, &k);
  
  int* N = new int[n]; // dynamic allocation
  for (int i = 0; i < n; ++i) {
    scanf("%d", &N[i]);
  }
  
  int left = 0;
  int right = MAX_W;
  
  while (left < right) {
    int mid = (left + right) / 2;
    int checked = check(N, n, k, mid);
    
    if (checked == n) {
      right = mid;
      start = 0; // reset start
    } else {
      left = mid + 1;
      start = checked; // update start
    }
  }
  
  cout << right << endl;
  
  delete[] N; // free memory
  return 0;
}