#include <cstdio>
#include <iostream>
using namespace std;

int check(int N[], int n, int k, int w) {
  int trucks = 1;
  int current_weight = 0;
  for (int i = 0; i < n; ++i) {
    if (N[i] > w) {
      return n + 1;
    }
    if (current_weight + N[i] <= w) {
      current_weight += N[i];
    } else {
      current_weight = N[i];
      trucks++;
    }
  }
  return trucks;
}

int main() {
  int MAX_W = 1000000000;
  int n, k;
  scanf("%d %d", &n, &k);
  int N[n];
  for (int i = 0; i < n; ++i) {
    scanf("%d", &N[i]);
  }
  int left = 0;
  int right = MAX_W;
  while (left < right) {
    int mid = (left + right) / 2;
    int required_trucks = check(N, n, k, mid);
    if (required_trucks <= k) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  cout << right << endl;
  return 0;
}